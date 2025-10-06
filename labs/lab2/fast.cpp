#include "image.h"
#include "load.h"
#include "window.h"
#include <chrono>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::vector;

/**
 * Class that stores a summary of an image.
 *
 * This summary is intended to contain a high-level representation of the
 * important parts of an image. I.e. it shall contain what a human eye would
 * find relevant, while ignoring things that the human eye would find
 * irrelevant.
 *
 * To approximate human perception, we store a series of booleans that indicate
 * if the brightness of the image has increased or not. We do this for all
 * horizontal lines and vertical lines in a downsampled version of the image.
 *
 * See the lab instructions for more details.
 *
 * Note: You will need to use this data structure as the key in a hash table. As
 * such, you will need to implement equality checks and a hash function for this
 * data structure.
 */

class Image_Summary {
public:
  // Horizontal increases in brightness.
  vector<bool> horizontal;

  // Vertical increases in brightness.
  vector<bool> vertical;
};

// Compute an Image_Summary from an image. This is described in detail in the
// lab instructions.
Image_Summary compute_summary(const Image &image) {
  const size_t summary_size = 6;
  Image_Summary result;
  Image small_image = image.shrink(summary_size + 1, summary_size + 1);

  //  Horisontellt
  for (size_t y = 0; y < summary_size + 1; y++) {
    for (size_t x = 0; x < summary_size; x++) {
      double left = small_image.pixel(x, y).brightness();
      double right = small_image.pixel(x + 1, y).brightness();
      result.horizontal.push_back(right > left);
    }
  }

  // Vertikalt
  for (size_t y = 0; y < summary_size; y++) {
    for (size_t x = 0; x < summary_size + 1; x++) {
      double up = small_image.pixel(x, y).brightness();
      double down = small_image.pixel(x, y + 1).brightness();
      result.vertical.push_back(down > up);
    }
  }

  return result;
}

size_t cusotm_hash(const std::vector<bool> &v) {
  size_t h = 0;
  for (bool b : v) {
    // Ta "hash" av bool (0 eller 1)
    size_t bh = static_cast<size_t>(b);

    // Kombinera med befintlig hash
    h ^= bh + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2);
  }
  return h;
}

bool operator==(const Image_Summary &lhs, const Image_Summary &rhs) {
  return lhs.vertical == rhs.vertical && lhs.horizontal == rhs.horizontal;
}

namespace std {
// Definiera en typ som specialiserar std::hash för vår typ:
template <> class hash<Image_Summary> {
public:
  // Typen ska kunna användas som ett funktionsobjekt.
  // Vi behöver därför överlagra funktionsanropsoperatorn (operator ()).
  size_t operator()(const Image_Summary &to_hash) const {
    size_t h1 = cusotm_hash(to_hash.vertical);
    size_t h2 = cusotm_hash(to_hash.horizontal);
    // cout << "h1: " << h1 << endl;
    // cout << "h2: " << h2 << endl;
    auto result = h1 ^ (h2 << 1);
    // cout << "Result: " << result << endl;
    return result; // or use boost::hash_combine
  }
};
} // namespace std

int main(int argc, const char *argv[]) {
  WindowPtr window = Window::create(argc, argv);

  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " [--nopause] [--nowindow] <directory>"
         << endl;
    cerr << "Missing directory containing files!" << endl;
    return 1;
  }

  vector<string> files = list_files(argv[1]);
  cout << "Found " << files.size() << " image files." << endl;

  if (files.size() <= 0) {
    cerr << "No files found! Make sure you entered a proper path!" << endl;
    return 1;
  }

  auto begin = std::chrono::high_resolution_clock::now();

  window->show_single("Loading images...", load_image(files[0]), false);


  /**
   * TODO: DONE
   * - For each file:
   * - Load the file
   * - Compute its summary
   */
  unordered_map<Image_Summary, vector<string>> summaries;

  auto load_time = std::chrono::high_resolution_clock::now();
  cout << "Loading images took: "
       << std::chrono::duration_cast<std::chrono::milliseconds>(load_time -
                                                                begin)
              .count()
       << " milliseconds." << endl;

  window->show_single("Comparing images...", load_image(files[1]), false);

  for (const auto &file : files) {
    Image img = load_image(file);
    Image_Summary summary = compute_summary(img);
    summaries[summary].push_back(file);

    //cout << "File" << file << endl << endl;
  }

  for (auto &[summary, filenames] : summaries) {
    if (filenames.size() > 1) {
      window->report_match(filenames); // report this group of duplicates
    }
  }

  auto end = std::chrono::high_resolution_clock::now();
  cout << "Total time: "
       << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin)
              .count()
       << " milliseconds." << endl;

  /**
   * TODO:
   * - Display sets of files with equal summaries
   */

  return 0;
}
