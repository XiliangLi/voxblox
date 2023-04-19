#include "voxblox/core/semantic_color_map.h"

namespace voxblox {
SemanticColorMap SemanticColorMap::create(const ClassTask& class_task) {
  switch (class_task) {
    case kCoco80:
      return CocoColorMap();
    case kNyu13:
      return Nyu13ColorMap();
  }
}

void SemanticColorMap::getColor(const SemanticLabel& semantic_label,
                                Color* color) const {
  CHECK_NOTNULL(color);
  color->r = color_code_.at(semantic_label)[0];
  color->g = color_code_.at(semantic_label)[1];
  color->b = color_code_.at(semantic_label)[2];
}

// NYUv2 13 class task color coding defined in SceneNet.
Nyu13ColorMap::Nyu13ColorMap()
    : SemanticColorMap({{200, 200, 200},    // BG
                        {20, 20, 20},       // Unknown
                        {0, 128, 128},      // Bed
                        {250, 50, 50},      // Books
                        {102, 0, 204},      // Ceiling
                        {50, 50, 250},      // Chair
                        {220, 220, 220},    // Floor
                        {255, 69, 20},      // Furniture
                        {255, 20, 127},     // Objects
                        {50, 50, 150},      // Picture
                        {222, 180, 140},    // Sofa
                        {50, 250, 50},      // Table
                        {255, 215, 0},      // TV
                        {150, 150, 150},    // Wall
                        {0, 255, 255}}) {}  // Window

// COCO 80 class task color coding using the PASCAL VOC color map.
CocoColorMap::CocoColorMap()
    : SemanticColorMap(
          {{200, 200, 200}, {128, 0, 0},    {0, 128, 0},    {128, 128, 0},
           {0, 0, 128},     {128, 0, 128},  {0, 128, 128},  {128, 128, 128},
           {64, 0, 0},      {192, 0, 0},    {64, 128, 0},   {192, 128, 0},
           {64, 0, 128},    {192, 0, 128},  {64, 128, 128}, {192, 128, 128},
           {0, 64, 0},      {128, 64, 0},   {0, 192, 0},    {128, 192, 0},
           {0, 64, 128},    {128, 64, 128}, {0, 192, 128},  {128, 192, 128},
           {64, 64, 0},     {192, 64, 0},   {64, 192, 0},   {192, 192, 0},
           {64, 64, 128},   {192, 64, 128}, {64, 192, 128}, {192, 192, 128},
           {0, 0, 64},      {128, 0, 64},   {0, 128, 64},   {128, 128, 64},
           {0, 0, 192},     {128, 0, 192},  {0, 128, 192},  {128, 128, 192},
           {64, 0, 64},     {192, 0, 64},   {64, 128, 64},  {192, 128, 64},
           {64, 0, 192},    {192, 0, 192},  {64, 128, 192}, {192, 128, 192},
           {0, 64, 64},     {128, 64, 64},  {0, 192, 64},   {128, 192, 64},
           {0, 64, 192},    {128, 64, 192}, {0, 192, 192},  {128, 192, 192}, // class 55
           {64, 64, 64},    {192, 64, 64},  {64, 192, 64},  {192, 192, 64},
           {64, 64, 192},   {192, 64, 192}, {64, 192, 192}, {192, 192, 192},
           {32, 0, 0},      {160, 0, 0},    {32, 128, 0},   {160, 128, 0},
           {32, 0, 128},    {160, 0, 128},  {32, 128, 128}, {160, 128, 128},
           {96, 0, 0},      {224, 0, 0},    {96, 128, 0},   {224, 128, 0},
           {96, 0, 128},    {224, 0, 128},  {96, 128, 128}, {224, 128, 128},
           {32, 64, 0},     {160, 64, 0},   {32, 192, 0},   {160, 192, 0},
           {32, 64, 128},   {160, 64, 128}, {32, 192, 128}, {160, 192, 128},
           {96, 64, 0},     {224, 64, 0},   {96, 192, 0},   {224, 192, 0},
           {96, 64, 128},   {224, 64, 128}, {96, 192, 128}, {224, 192, 128},
           {32, 0, 64},     {160, 0, 64},   {32, 128, 64},  {160, 128, 64},
           {32, 0, 192},    {160, 0, 192},  {32, 128, 192}, {160, 128, 192},
           {96, 0, 64},     {224, 0, 64},   {96, 128, 64},  {224, 128, 64},
           {96, 0, 192},    {224, 0, 192},  {96, 128, 192}, {224, 128, 192},
           {32, 64, 64},    {160, 64, 64},  {32, 192, 64},  {160, 192, 64},
           {32, 64, 192},   {160, 64, 192}, {32, 192, 192}, {160, 192, 192},
           {96, 64, 64},    {224, 64, 64},  {96, 192, 64},  {224, 192, 64},
           {96, 64, 192},   {224, 64, 192}, {96, 192, 192}, {224, 192, 192},
           {0, 32, 0},      {128, 32, 0},   {0, 160, 0},    {128, 160, 0},
           {0, 32, 128},    {128, 32, 128}, {0, 160, 128},  {128, 160, 128},
           {64, 32, 0},     {192, 32, 0},   {64, 160, 0},   {192, 160, 0},
           {64, 32, 128},   {192, 32, 128}, {64, 160, 128}, {192, 160, 128},
           {0, 96, 0},      {128, 96, 0},   {0, 224, 0},    {128, 224, 0},
           {0, 96, 128},    {128, 96, 128}, {0, 224, 128},  {128, 224, 128},
           {64, 96, 0},     {192, 96, 0},   {64, 224, 0},   {192, 224, 0},
           {64, 96, 128},   {192, 96, 128}, {64, 224, 128}, {192, 224, 128},
           {0, 32, 64},     {128, 32, 64},  {0, 160, 64},   {128, 160, 64},
           {0, 32, 192},    {128, 32, 192}, {0, 160, 192},  {128, 160, 192},
           {64, 32, 64},    {192, 32, 64},  {64, 160, 64},  {192, 160, 64},
           {64, 32, 192},   {192, 32, 192}, {64, 160, 192}, {192, 160, 192},
           {0, 96, 64},     {128, 96, 64},  {0, 224, 64},   {128, 224, 64},
           {0, 96, 192},    {128, 96, 192}, {0, 224, 192},  {128, 224, 192},
           {64, 96, 64},    {192, 96, 64},  {64, 224, 64},  {192, 224, 64},
           {64, 96, 192},   {192, 96, 192}, {64, 224, 192}, {192, 224, 192},
           {32, 32, 0},     {160, 32, 0},   {32, 160, 0},   {160, 160, 0},
           {32, 32, 128},   {160, 32, 128}, {32, 160, 128}, {160, 160, 128},
           {96, 32, 0},     {224, 32, 0},   {96, 160, 0},   {224, 160, 0},
           {96, 32, 128},   {224, 32, 128}, {96, 160, 128}, {224, 160, 128},
           {32, 96, 0},     {160, 96, 0},   {32, 224, 0},   {160, 224, 0},
           {32, 96, 128},   {160, 96, 128}, {32, 224, 128}, {160, 224, 128},
           {96, 96, 0},     {224, 96, 0},   {96, 224, 0},   {224, 224, 0},
           {96, 96, 128},   {224, 96, 128}, {96, 224, 128}, {224, 224, 128},
           {32, 32, 64},    {160, 32, 64},  {32, 160, 64},  {160, 160, 64},
           {32, 32, 192},   {160, 32, 192}, {32, 160, 192}, {160, 160, 192},
           {96, 32, 64},    {224, 32, 64},  {96, 160, 64},  {224, 160, 64},
           {96, 32, 192},   {224, 32, 192}, {96, 160, 192}, {224, 160, 192},
           {32, 96, 64},    {160, 96, 64},  {32, 224, 64},  {160, 224, 64},
           {32, 96, 192},   {160, 96, 192}, {32, 224, 192}, {160, 224, 192},
           {96, 96, 64},    {224, 96, 64},  {96, 224, 64},  {224, 224, 64},
           {96, 96, 192},   {224, 96, 192}, {96, 224, 192}, {224, 224, 192}}) {
  // Defining some custom colors.
  // TODO(margaritaG): swap colors properly, else duplicate colors.
  color_code_[61] = {192, 128, 192};  // Dining table
  color_code_[57] = {192, 64, 64};    // Chair
  color_code_[14] = {64, 128, 128};   // Bench
  color_code_[63] = {0, 64, 192};     // TV
  color_code_[25] = {128, 64, 192};   // Backpack
  color_code_[42] = {64, 128, 64};    // Cup
  color_code_[29] = {128, 192, 192};  // Suitcase
  color_code_[65] = {64, 0, 128};     // Mouse
  color_code_[67] = {160, 128, 0};    // Keyboard
  color_code_[69] = {160, 0, 128};    // Microwave
  color_code_[59] = {64, 64, 128};    // Potted plant
  color_code_[73] = {64, 192, 0};     // Refrigerator
  // color_code_[73] = {224, 192, 224};     // Refrigerator
}

}  // namespace voxblox
