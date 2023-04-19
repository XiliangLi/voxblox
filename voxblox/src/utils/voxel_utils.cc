#include <iostream>
#include "voxblox/utils/voxel_utils.h"

#include "voxblox/core/color.h"
#include "voxblox/core/common.h"
#include "voxblox/core/voxel.h"

namespace voxblox {

template <>
void mergeVoxelAIntoVoxelB(const TsdfVoxel& voxel_A, TsdfVoxel* voxel_B) {
  float combined_weight = voxel_A.weight + voxel_B->weight;
  if (combined_weight > 0) {
    voxel_B->distance = (voxel_A.distance * voxel_A.weight +
                         voxel_B->distance * voxel_B->weight) /
                        combined_weight;

    // tempory voxel_A semantic count
    uint temp_a_count = voxel_A.semantic_count;
    // change black color to background
    if(Color(voxel_B->color.r, voxel_B->color.g, voxel_B->color.b) == Color::Black()) {
      voxel_B->color.r = Color::BGround().r;
      voxel_B->color.g = Color::BGround().g;
      voxel_B->color.b = Color::BGround().b;
      voxel_B->color.a = uint8_t(255);
    }
    // if(voxel_A.semantic_label > 0) {
    //   std::cout << " every ======A sematic label: " << voxel_A.semantic_label << std::endl;
    //   std::cout << " every ======A sematic count: " << voxel_A.semantic_count << std::endl;
    // }
    
    bool A_Black = Color(voxel_A.color.r, voxel_A.color.g, voxel_A.color.b) == Color::Black();

    // if(voxel_A.semantic_label == 0u && voxel_A.semantic_count > 0) std::cout << "======================== not 00000000000  " << voxel_A.semantic_count << std::endl;

    if(voxel_A.semantic_label == 0u && !A_Black) { temp_a_count = voxel_A.semantic_count * 0.5;}
    //   // std::cout << "==a " << unsigned(voxel_A.color.a) << std::endl;
    //   // std::cout << "==r " << unsigned(voxel_A.color.r) << std::endl;
    //   // std::cout << "==g " << unsigned(voxel_A.color.g) << std::endl;
    //   // std::cout << "==b " << unsigned(voxel_A.color.b) << std::endl;
      
    // if(temp_a_count > 0);
    //   // std::cout << " ======================== voxelA: " << temp_a_count << std::endl;}
    // // std::cout << " ======A sematic label: " << voxel_A.semantic_label << " =======B sematic label: " << voxel_B->semantic_label << std::endl;
    // // std::cout << " ======A sematic count: " << voxel_A.semantic_count << " ========B sematic count: " << voxel_B->semantic_count << std::endl;
    // }

    if(voxel_A.semantic_label == voxel_B->semantic_label) {
      voxel_B->semantic_count = (temp_a_count + voxel_B->semantic_count) / 1.5;
      if(voxel_B->semantic_label == 0u) voxel_B->semantic_count * 0.9;
      // voxel_B->color = voxel_A.color;
      // if(!((voxel_A.color.a == voxel_B->color.a) && (voxel_A.color.r == voxel_B->color.r) && (voxel_A.color.g == voxel_B->color.g) && (voxel_A.color.b == voxel_B->color.b))) {
      //   std::cout << " =================== voxelA_label  voxelB_label" << voxel_A.semantic_label << voxel_B->semantic_label << std::endl;
      //   std::cout << "a " << unsigned(voxel_A.color.a) << " " << unsigned(voxel_B->color.a) << std::endl;
      //   std::cout << "r " << unsigned(voxel_A.color.r) << " " << unsigned(voxel_B->color.r) << std::endl;
      //   std::cout << "g " << unsigned(voxel_A.color.g) << " " << unsigned(voxel_B->color.g) << std::endl;
      //   std::cout << "b " << unsigned(voxel_A.color.b) << " " << unsigned(voxel_B->color.b) << std::endl;
        // }

      // if( !(Color(voxel_A.color.r, voxel_A.color.g, voxel_A.color.b) == Color::Black()) && ((voxel_A.color.a != voxel_B->color.a) || 
      //     (voxel_A.color.r != voxel_B->color.r) || (voxel_A.color.g != voxel_B->color.g) || (voxel_A.color.b != voxel_B->color.b))) {
      //   // std::cout << " ======A sematic label: " << voxel_A.semantic_label << " =======B sematic label: " << voxel_B->semantic_label << std::endl;
      //   std::cout << " ======A sematic count: " << voxel_A.semantic_count << " ========B sematic count: " << voxel_B->semantic_count << std::endl;
      //   std::cout << "a " << unsigned(voxel_A.color.a) << " " << unsigned(voxel_B->color.a) << std::endl;
      //   std::cout << "r " << unsigned(voxel_A.color.r) << " " << unsigned(voxel_B->color.r) << std::endl;
      //   std::cout << "g " << unsigned(voxel_A.color.g) << " " << unsigned(voxel_B->color.g) << std::endl;
      //   std::cout << "b " << unsigned(voxel_A.color.b) << " " << unsigned(voxel_B->color.b) << std::endl;
      // }

      
    } else if(temp_a_count >= voxel_B->semantic_count && temp_a_count > 1u || (temp_a_count == 1u && voxel_B->semantic_count == 0u)) {
    // std::cout << " ======A > B sematic label: " << voxel_A.semantic_label << " =======B sematic label: " << voxel_B->semantic_label << std::endl;
    // if(voxel_A.semantic_label == 0u)
    // std::cout << " ======A > B sematic count: " << temp_a_count << " ========B sematic count: " << voxel_B->semantic_count << std::endl;
      voxel_B->semantic_label = voxel_A.semantic_label;
      voxel_B->semantic_count = temp_a_count - voxel_B->semantic_count;
      voxel_B->color = voxel_A.color;
      voxel_B->color.a = uint8_t(255);
      // voxel_B->semantic_count *= 1.5;
    } else {
      // if(voxel_A.semantic_label != 0u) std::cout << "no instance 0 but not fuse: " << voxel_A.semantic_count << " " << voxel_B->semantic_count << std::endl;
      // std::cout << " ======A < B sematic label: " << voxel_A.semantic_label << " =======B sematic label: " << voxel_B->semantic_label << std::endl;
      // std::cout << " ======A < B sematic count: " << temp_a_count << " ========B sematic count: " << voxel_B->semantic_count << std::endl;
      if(voxel_B->semantic_count > temp_a_count) {
        voxel_B->semantic_count -= temp_a_count;
      } else {
        voxel_B->semantic_count = 0;
      }
      
      // voxel_B->semantic_count *= 1.5;
    }
    // if(voxel_B->semantic_label == 0u) {voxel_B->semantic_count *= 0.1;
    // if(voxel_B->semantic_count > 0)
      // std::cout << " ======================== voxelB: " << voxel_B->semantic_count << std::endl;} 
    // if(voxel_B->semantic_label == 0u) std::cout << "===============why" << voxel_B->semantic_count << std::endl;
    // voxel_B->color.a = uint8_t(255);

    /*
    // retain voxel color if old voxel is not background color
    if((Color(voxel_A.color.r, voxel_A.color.g, voxel_A.color.b) == Color::BGround() ||
        (Color(voxel_A.color.r, voxel_A.color.g, voxel_A.color.b) == Color::Black()))) {
      voxel_B->color = voxel_B->color;
    } else if(!(Color(voxel_A.color.r, voxel_A.color.g, voxel_A.color.b) == Color::BGround()) || 
                  (!(Color(voxel_A.color.r, voxel_A.color.g, voxel_A.color.b) == Color::Black()))) {
      voxel_B->color = voxel_A.color;
    } else {
      // reduce black weight
      // if(Color(voxel_B->color.r, voxel_B->color.g, voxel_B->color.b) == Color::Black()) {
      //   voxel_B->color = Color::blendTwoColors(voxel_A.color, 0.9 * voxel_A.weight,
      //                                      voxel_B->color, 0.1 * voxel_A.weight);
      // } else {
        voxel_B->color = Color::blendTwoColors(voxel_A.color, voxel_A.weight,
                                           voxel_B->color, voxel_B->weight);
      // }
      
    }
    */

    voxel_B->weight = combined_weight;
    voxel_B->history.insert(voxel_A.history.begin(), voxel_A.history.end());
  }
}

template <>
void mergeVoxelAIntoVoxelB(const EsdfVoxel& voxel_A, EsdfVoxel* voxel_B) {
  if (voxel_A.observed && voxel_B->observed) {
    voxel_B->distance = (voxel_A.distance + voxel_B->distance) / 2.f;
  } else if (voxel_A.observed && !voxel_B->observed) {
    voxel_B->distance = voxel_A.distance;
  }
  voxel_B->observed = voxel_B->observed || voxel_A.observed;
}

template <>
void mergeVoxelAIntoVoxelB(const OccupancyVoxel& voxel_A,
                           OccupancyVoxel* voxel_B) {
  voxel_B->probability_log += voxel_A.probability_log;
  voxel_B->observed = voxel_B->observed || voxel_A.observed;
}

}  // namespace voxblox
