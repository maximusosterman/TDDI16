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
  const size_t summary_size = 8;
  Image_Summary result;
  Image small_image = image.shrink(summary_size + 1, summary_size + 1);
  // Horisontellt
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

  /**
   * TODO:
   * - For each file:
   * - Load the file
   * - Compute its summary
   */
  vector<Image_Summary> summaries;
  for (const auto &i : files) {
    Image img = load_image(i);
    summaries.push_back(compute_summary(img));
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
