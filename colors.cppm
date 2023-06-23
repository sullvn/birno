module;

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <span>
#include <string_view>
#include <unordered_map>

export module colors;

namespace colors {
export struct RGB {
  const std::uint8_t r;
  const std::uint8_t g;
  const std::uint8_t b;
};

export constexpr auto byte_color(const std::span<const RGB> &colors,
                                 std::byte byte) -> const RGB & {
  constexpr auto byte_permutations = std::numeric_limits<std::uint8_t>::max();

  const auto stride = static_cast<double>(colors.size()) /
                      static_cast<double>(byte_permutations);
  const auto index =
      static_cast<std::size_t>(std::floor(static_cast<double>(byte) * stride));

  return colors[index];
}

template <typename V, typename... T>
constexpr auto array_of(T &&...t) -> std::array<V, sizeof...(T)> {
  return {{std::forward<T>(t)...}};
}

export inline constexpr auto viridis = array_of<RGB>(
    RGB{68, 1, 84}, RGB{68, 2, 86}, RGB{69, 4, 87}, RGB{69, 5, 89},
    RGB{70, 7, 90}, RGB{70, 8, 92}, RGB{70, 10, 93}, RGB{70, 11, 94},
    RGB{71, 13, 96}, RGB{71, 14, 97}, RGB{71, 16, 99}, RGB{71, 17, 100},
    RGB{71, 19, 101}, RGB{72, 20, 103}, RGB{72, 22, 104}, RGB{72, 23, 105},
    RGB{72, 24, 106}, RGB{72, 26, 108}, RGB{72, 27, 109}, RGB{72, 28, 110},
    RGB{72, 29, 111}, RGB{72, 31, 112}, RGB{72, 32, 113}, RGB{72, 33, 115},
    RGB{72, 35, 116}, RGB{72, 36, 117}, RGB{72, 37, 118}, RGB{72, 38, 119},
    RGB{72, 40, 120}, RGB{72, 41, 121}, RGB{71, 42, 122}, RGB{71, 44, 122},
    RGB{71, 45, 123}, RGB{71, 46, 124}, RGB{71, 47, 125}, RGB{70, 48, 126},
    RGB{70, 50, 126}, RGB{70, 51, 127}, RGB{70, 52, 128}, RGB{69, 53, 129},
    RGB{69, 55, 129}, RGB{69, 56, 130}, RGB{68, 57, 131}, RGB{68, 58, 131},
    RGB{68, 59, 132}, RGB{67, 61, 132}, RGB{67, 62, 133}, RGB{66, 63, 133},
    RGB{66, 64, 134}, RGB{66, 65, 134}, RGB{65, 66, 135}, RGB{65, 68, 135},
    RGB{64, 69, 136}, RGB{64, 70, 136}, RGB{63, 71, 136}, RGB{63, 72, 137},
    RGB{62, 73, 137}, RGB{62, 74, 137}, RGB{62, 76, 138}, RGB{61, 77, 138},
    RGB{61, 78, 138}, RGB{60, 79, 138}, RGB{60, 80, 139}, RGB{59, 81, 139},
    RGB{59, 82, 139}, RGB{58, 83, 139}, RGB{58, 84, 140}, RGB{57, 85, 140},
    RGB{57, 86, 140}, RGB{56, 88, 140}, RGB{56, 89, 140}, RGB{55, 90, 140},
    RGB{55, 91, 141}, RGB{54, 92, 141}, RGB{54, 93, 141}, RGB{53, 94, 141},
    RGB{53, 95, 141}, RGB{52, 96, 141}, RGB{52, 97, 141}, RGB{51, 98, 141},
    RGB{51, 99, 141}, RGB{50, 100, 142}, RGB{50, 101, 142}, RGB{49, 102, 142},
    RGB{49, 103, 142}, RGB{49, 104, 142}, RGB{48, 105, 142}, RGB{48, 106, 142},
    RGB{47, 107, 142}, RGB{47, 108, 142}, RGB{46, 109, 142}, RGB{46, 110, 142},
    RGB{46, 111, 142}, RGB{45, 112, 142}, RGB{45, 113, 142}, RGB{44, 113, 142},
    RGB{44, 114, 142}, RGB{44, 115, 142}, RGB{43, 116, 142}, RGB{43, 117, 142},
    RGB{42, 118, 142}, RGB{42, 119, 142}, RGB{42, 120, 142}, RGB{41, 121, 142},
    RGB{41, 122, 142}, RGB{41, 123, 142}, RGB{40, 124, 142}, RGB{40, 125, 142},
    RGB{39, 126, 142}, RGB{39, 127, 142}, RGB{39, 128, 142}, RGB{38, 129, 142},
    RGB{38, 130, 142}, RGB{38, 130, 142}, RGB{37, 131, 142}, RGB{37, 132, 142},
    RGB{37, 133, 142}, RGB{36, 134, 142}, RGB{36, 135, 142}, RGB{35, 136, 142},
    RGB{35, 137, 142}, RGB{35, 138, 141}, RGB{34, 139, 141}, RGB{34, 140, 141},
    RGB{34, 141, 141}, RGB{33, 142, 141}, RGB{33, 143, 141}, RGB{33, 144, 141},
    RGB{33, 145, 140}, RGB{32, 146, 140}, RGB{32, 146, 140}, RGB{32, 147, 140},
    RGB{31, 148, 140}, RGB{31, 149, 139}, RGB{31, 150, 139}, RGB{31, 151, 139},
    RGB{31, 152, 139}, RGB{31, 153, 138}, RGB{31, 154, 138}, RGB{30, 155, 138},
    RGB{30, 156, 137}, RGB{30, 157, 137}, RGB{31, 158, 137}, RGB{31, 159, 136},
    RGB{31, 160, 136}, RGB{31, 161, 136}, RGB{31, 161, 135}, RGB{31, 162, 135},
    RGB{32, 163, 134}, RGB{32, 164, 134}, RGB{33, 165, 133}, RGB{33, 166, 133},
    RGB{34, 167, 133}, RGB{34, 168, 132}, RGB{35, 169, 131}, RGB{36, 170, 131},
    RGB{37, 171, 130}, RGB{37, 172, 130}, RGB{38, 173, 129}, RGB{39, 173, 129},
    RGB{40, 174, 128}, RGB{41, 175, 127}, RGB{42, 176, 127}, RGB{44, 177, 126},
    RGB{45, 178, 125}, RGB{46, 179, 124}, RGB{47, 180, 124}, RGB{49, 181, 123},
    RGB{50, 182, 122}, RGB{52, 182, 121}, RGB{53, 183, 121}, RGB{55, 184, 120},
    RGB{56, 185, 119}, RGB{58, 186, 118}, RGB{59, 187, 117}, RGB{61, 188, 116},
    RGB{63, 188, 115}, RGB{64, 189, 114}, RGB{66, 190, 113}, RGB{68, 191, 112},
    RGB{70, 192, 111}, RGB{72, 193, 110}, RGB{74, 193, 109}, RGB{76, 194, 108},
    RGB{78, 195, 107}, RGB{80, 196, 106}, RGB{82, 197, 105}, RGB{84, 197, 104},
    RGB{86, 198, 103}, RGB{88, 199, 101}, RGB{90, 200, 100}, RGB{92, 200, 99},
    RGB{94, 201, 98}, RGB{96, 202, 96}, RGB{99, 203, 95}, RGB{101, 203, 94},
    RGB{103, 204, 92}, RGB{105, 205, 91}, RGB{108, 205, 90}, RGB{110, 206, 88},
    RGB{112, 207, 87}, RGB{115, 208, 86}, RGB{117, 208, 84}, RGB{119, 209, 83},
    RGB{122, 209, 81}, RGB{124, 210, 80}, RGB{127, 211, 78}, RGB{129, 211, 77},
    RGB{132, 212, 75}, RGB{134, 213, 73}, RGB{137, 213, 72}, RGB{139, 214, 70},
    RGB{142, 214, 69}, RGB{144, 215, 67}, RGB{147, 215, 65}, RGB{149, 216, 64},
    RGB{152, 216, 62}, RGB{155, 217, 60}, RGB{157, 217, 59}, RGB{160, 218, 57},
    RGB{162, 218, 55}, RGB{165, 219, 54}, RGB{168, 219, 52}, RGB{170, 220, 50},
    RGB{173, 220, 48}, RGB{176, 221, 47}, RGB{178, 221, 45}, RGB{181, 222, 43},
    RGB{184, 222, 41}, RGB{186, 222, 40}, RGB{189, 223, 38}, RGB{192, 223, 37},
    RGB{194, 223, 35}, RGB{197, 224, 33}, RGB{200, 224, 32}, RGB{202, 225, 31},
    RGB{205, 225, 29}, RGB{208, 225, 28}, RGB{210, 226, 27}, RGB{213, 226, 26},
    RGB{216, 226, 25}, RGB{218, 227, 25}, RGB{221, 227, 24}, RGB{223, 227, 24},
    RGB{226, 228, 24}, RGB{229, 228, 25}, RGB{231, 228, 25}, RGB{234, 229, 26},
    RGB{236, 229, 27}, RGB{239, 229, 28}, RGB{241, 229, 29}, RGB{244, 230, 30},
    RGB{246, 230, 32}, RGB{248, 230, 33}, RGB{251, 231, 35}, RGB{253, 231, 37});

export inline constexpr auto magma = array_of<RGB>(
    RGB{0, 0, 4}, RGB{1, 0, 5}, RGB{1, 1, 6}, RGB{1, 1, 8}, RGB{2, 1, 9},
    RGB{2, 2, 11}, RGB{2, 2, 13}, RGB{3, 3, 15}, RGB{3, 3, 18}, RGB{4, 4, 20},
    RGB{5, 4, 22}, RGB{6, 5, 24}, RGB{6, 5, 26}, RGB{7, 6, 28}, RGB{8, 7, 30},
    RGB{9, 7, 32}, RGB{10, 8, 34}, RGB{11, 9, 36}, RGB{12, 9, 38},
    RGB{13, 10, 41}, RGB{14, 11, 43}, RGB{16, 11, 45}, RGB{17, 12, 47},
    RGB{18, 13, 49}, RGB{19, 13, 52}, RGB{20, 14, 54}, RGB{21, 14, 56},
    RGB{22, 15, 59}, RGB{24, 15, 61}, RGB{25, 16, 63}, RGB{26, 16, 66},
    RGB{28, 16, 68}, RGB{29, 17, 71}, RGB{30, 17, 73}, RGB{32, 17, 75},
    RGB{33, 17, 78}, RGB{34, 17, 80}, RGB{36, 18, 83}, RGB{37, 18, 85},
    RGB{39, 18, 88}, RGB{41, 17, 90}, RGB{42, 17, 92}, RGB{44, 17, 95},
    RGB{45, 17, 97}, RGB{47, 17, 99}, RGB{49, 17, 101}, RGB{51, 16, 103},
    RGB{52, 16, 105}, RGB{54, 16, 107}, RGB{56, 16, 108}, RGB{57, 15, 110},
    RGB{59, 15, 112}, RGB{61, 15, 113}, RGB{63, 15, 114}, RGB{64, 15, 116},
    RGB{66, 15, 117}, RGB{68, 15, 118}, RGB{69, 16, 119}, RGB{71, 16, 120},
    RGB{73, 16, 120}, RGB{74, 16, 121}, RGB{76, 17, 122}, RGB{78, 17, 123},
    RGB{79, 18, 123}, RGB{81, 18, 124}, RGB{82, 19, 124}, RGB{84, 19, 125},
    RGB{86, 20, 125}, RGB{87, 21, 126}, RGB{89, 21, 126}, RGB{90, 22, 126},
    RGB{92, 22, 127}, RGB{93, 23, 127}, RGB{95, 24, 127}, RGB{96, 24, 128},
    RGB{98, 25, 128}, RGB{100, 26, 128}, RGB{101, 26, 128}, RGB{103, 27, 128},
    RGB{104, 28, 129}, RGB{106, 28, 129}, RGB{107, 29, 129}, RGB{109, 29, 129},
    RGB{110, 30, 129}, RGB{112, 31, 129}, RGB{114, 31, 129}, RGB{115, 32, 129},
    RGB{117, 33, 129}, RGB{118, 33, 129}, RGB{120, 34, 129}, RGB{121, 34, 130},
    RGB{123, 35, 130}, RGB{124, 35, 130}, RGB{126, 36, 130}, RGB{128, 37, 130},
    RGB{129, 37, 129}, RGB{131, 38, 129}, RGB{132, 38, 129}, RGB{134, 39, 129},
    RGB{136, 39, 129}, RGB{137, 40, 129}, RGB{139, 41, 129}, RGB{140, 41, 129},
    RGB{142, 42, 129}, RGB{144, 42, 129}, RGB{145, 43, 129}, RGB{147, 43, 128},
    RGB{148, 44, 128}, RGB{150, 44, 128}, RGB{152, 45, 128}, RGB{153, 45, 128},
    RGB{155, 46, 127}, RGB{156, 46, 127}, RGB{158, 47, 127}, RGB{160, 47, 127},
    RGB{161, 48, 126}, RGB{163, 48, 126}, RGB{165, 49, 126}, RGB{166, 49, 125},
    RGB{168, 50, 125}, RGB{170, 51, 125}, RGB{171, 51, 124}, RGB{173, 52, 124},
    RGB{174, 52, 123}, RGB{176, 53, 123}, RGB{178, 53, 123}, RGB{179, 54, 122},
    RGB{181, 54, 122}, RGB{183, 55, 121}, RGB{184, 55, 121}, RGB{186, 56, 120},
    RGB{188, 57, 120}, RGB{189, 57, 119}, RGB{191, 58, 119}, RGB{192, 58, 118},
    RGB{194, 59, 117}, RGB{196, 60, 117}, RGB{197, 60, 116}, RGB{199, 61, 115},
    RGB{200, 62, 115}, RGB{202, 62, 114}, RGB{204, 63, 113}, RGB{205, 64, 113},
    RGB{207, 64, 112}, RGB{208, 65, 111}, RGB{210, 66, 111}, RGB{211, 67, 110},
    RGB{213, 68, 109}, RGB{214, 69, 108}, RGB{216, 69, 108}, RGB{217, 70, 107},
    RGB{219, 71, 106}, RGB{220, 72, 105}, RGB{222, 73, 104}, RGB{223, 74, 104},
    RGB{224, 76, 103}, RGB{226, 77, 102}, RGB{227, 78, 101}, RGB{228, 79, 100},
    RGB{229, 80, 100}, RGB{231, 82, 99}, RGB{232, 83, 98}, RGB{233, 84, 98},
    RGB{234, 86, 97}, RGB{235, 87, 96}, RGB{236, 88, 96}, RGB{237, 90, 95},
    RGB{238, 91, 94}, RGB{239, 93, 94}, RGB{240, 95, 94}, RGB{241, 96, 93},
    RGB{242, 98, 93}, RGB{242, 100, 92}, RGB{243, 101, 92}, RGB{244, 103, 92},
    RGB{244, 105, 92}, RGB{245, 107, 92}, RGB{246, 108, 92}, RGB{246, 110, 92},
    RGB{247, 112, 92}, RGB{247, 114, 92}, RGB{248, 116, 92}, RGB{248, 118, 92},
    RGB{249, 120, 93}, RGB{249, 121, 93}, RGB{249, 123, 93}, RGB{250, 125, 94},
    RGB{250, 127, 94}, RGB{250, 129, 95}, RGB{251, 131, 95}, RGB{251, 133, 96},
    RGB{251, 135, 97}, RGB{252, 137, 97}, RGB{252, 138, 98}, RGB{252, 140, 99},
    RGB{252, 142, 100}, RGB{252, 144, 101}, RGB{253, 146, 102},
    RGB{253, 148, 103}, RGB{253, 150, 104}, RGB{253, 152, 105},
    RGB{253, 154, 106}, RGB{253, 155, 107}, RGB{254, 157, 108},
    RGB{254, 159, 109}, RGB{254, 161, 110}, RGB{254, 163, 111},
    RGB{254, 165, 113}, RGB{254, 167, 114}, RGB{254, 169, 115},
    RGB{254, 170, 116}, RGB{254, 172, 118}, RGB{254, 174, 119},
    RGB{254, 176, 120}, RGB{254, 178, 122}, RGB{254, 180, 123},
    RGB{254, 182, 124}, RGB{254, 183, 126}, RGB{254, 185, 127},
    RGB{254, 187, 129}, RGB{254, 189, 130}, RGB{254, 191, 132},
    RGB{254, 193, 133}, RGB{254, 194, 135}, RGB{254, 196, 136},
    RGB{254, 198, 138}, RGB{254, 200, 140}, RGB{254, 202, 141},
    RGB{254, 204, 143}, RGB{254, 205, 144}, RGB{254, 207, 146},
    RGB{254, 209, 148}, RGB{254, 211, 149}, RGB{254, 213, 151},
    RGB{254, 215, 153}, RGB{254, 216, 154}, RGB{253, 218, 156},
    RGB{253, 220, 158}, RGB{253, 222, 160}, RGB{253, 224, 161},
    RGB{253, 226, 163}, RGB{253, 227, 165}, RGB{253, 229, 167},
    RGB{253, 231, 169}, RGB{253, 233, 170}, RGB{253, 235, 172},
    RGB{252, 236, 174}, RGB{252, 238, 176}, RGB{252, 240, 178},
    RGB{252, 242, 180}, RGB{252, 244, 182}, RGB{252, 246, 184},
    RGB{252, 247, 185}, RGB{252, 249, 187}, RGB{252, 251, 189},
    RGB{252, 253, 191});

export inline constexpr auto inferno = array_of<RGB>(
    RGB{0, 0, 4}, RGB{1, 0, 5}, RGB{1, 1, 6}, RGB{1, 1, 8}, RGB{2, 1, 10},
    RGB{2, 2, 12}, RGB{2, 2, 14}, RGB{3, 2, 16}, RGB{4, 3, 18}, RGB{4, 3, 20},
    RGB{5, 4, 23}, RGB{6, 4, 25}, RGB{7, 5, 27}, RGB{8, 5, 29}, RGB{9, 6, 31},
    RGB{10, 7, 34}, RGB{11, 7, 36}, RGB{12, 8, 38}, RGB{13, 8, 41},
    RGB{14, 9, 43}, RGB{16, 9, 45}, RGB{17, 10, 48}, RGB{18, 10, 50},
    RGB{20, 11, 52}, RGB{21, 11, 55}, RGB{22, 11, 57}, RGB{24, 12, 60},
    RGB{25, 12, 62}, RGB{27, 12, 65}, RGB{28, 12, 67}, RGB{30, 12, 69},
    RGB{31, 12, 72}, RGB{33, 12, 74}, RGB{35, 12, 76}, RGB{36, 12, 79},
    RGB{38, 12, 81}, RGB{40, 11, 83}, RGB{41, 11, 85}, RGB{43, 11, 87},
    RGB{45, 11, 89}, RGB{47, 10, 91}, RGB{49, 10, 92}, RGB{50, 10, 94},
    RGB{52, 10, 95}, RGB{54, 9, 97}, RGB{56, 9, 98}, RGB{57, 9, 99},
    RGB{59, 9, 100}, RGB{61, 9, 101}, RGB{62, 9, 102}, RGB{64, 10, 103},
    RGB{66, 10, 104}, RGB{68, 10, 104}, RGB{69, 10, 105}, RGB{71, 11, 106},
    RGB{73, 11, 106}, RGB{74, 12, 107}, RGB{76, 12, 107}, RGB{77, 13, 108},
    RGB{79, 13, 108}, RGB{81, 14, 108}, RGB{82, 14, 109}, RGB{84, 15, 109},
    RGB{85, 15, 109}, RGB{87, 16, 110}, RGB{89, 16, 110}, RGB{90, 17, 110},
    RGB{92, 18, 110}, RGB{93, 18, 110}, RGB{95, 19, 110}, RGB{97, 19, 110},
    RGB{98, 20, 110}, RGB{100, 21, 110}, RGB{101, 21, 110}, RGB{103, 22, 110},
    RGB{105, 22, 110}, RGB{106, 23, 110}, RGB{108, 24, 110}, RGB{109, 24, 110},
    RGB{111, 25, 110}, RGB{113, 25, 110}, RGB{114, 26, 110}, RGB{116, 26, 110},
    RGB{117, 27, 110}, RGB{119, 28, 109}, RGB{120, 28, 109}, RGB{122, 29, 109},
    RGB{124, 29, 109}, RGB{125, 30, 109}, RGB{127, 30, 108}, RGB{128, 31, 108},
    RGB{130, 32, 108}, RGB{132, 32, 107}, RGB{133, 33, 107}, RGB{135, 33, 107},
    RGB{136, 34, 106}, RGB{138, 34, 106}, RGB{140, 35, 105}, RGB{141, 35, 105},
    RGB{143, 36, 105}, RGB{144, 37, 104}, RGB{146, 37, 104}, RGB{147, 38, 103},
    RGB{149, 38, 103}, RGB{151, 39, 102}, RGB{152, 39, 102}, RGB{154, 40, 101},
    RGB{155, 41, 100}, RGB{157, 41, 100}, RGB{159, 42, 99}, RGB{160, 42, 99},
    RGB{162, 43, 98}, RGB{163, 44, 97}, RGB{165, 44, 96}, RGB{166, 45, 96},
    RGB{168, 46, 95}, RGB{169, 46, 94}, RGB{171, 47, 94}, RGB{173, 48, 93},
    RGB{174, 48, 92}, RGB{176, 49, 91}, RGB{177, 50, 90}, RGB{179, 50, 90},
    RGB{180, 51, 89}, RGB{182, 52, 88}, RGB{183, 53, 87}, RGB{185, 53, 86},
    RGB{186, 54, 85}, RGB{188, 55, 84}, RGB{189, 56, 83}, RGB{191, 57, 82},
    RGB{192, 58, 81}, RGB{193, 58, 80}, RGB{195, 59, 79}, RGB{196, 60, 78},
    RGB{198, 61, 77}, RGB{199, 62, 76}, RGB{200, 63, 75}, RGB{202, 64, 74},
    RGB{203, 65, 73}, RGB{204, 66, 72}, RGB{206, 67, 71}, RGB{207, 68, 70},
    RGB{208, 69, 69}, RGB{210, 70, 68}, RGB{211, 71, 67}, RGB{212, 72, 66},
    RGB{213, 74, 65}, RGB{215, 75, 63}, RGB{216, 76, 62}, RGB{217, 77, 61},
    RGB{218, 78, 60}, RGB{219, 80, 59}, RGB{221, 81, 58}, RGB{222, 82, 56},
    RGB{223, 83, 55}, RGB{224, 85, 54}, RGB{225, 86, 53}, RGB{226, 87, 52},
    RGB{227, 89, 51}, RGB{228, 90, 49}, RGB{229, 92, 48}, RGB{230, 93, 47},
    RGB{231, 94, 46}, RGB{232, 96, 45}, RGB{233, 97, 43}, RGB{234, 99, 42},
    RGB{235, 100, 41}, RGB{235, 102, 40}, RGB{236, 103, 38}, RGB{237, 105, 37},
    RGB{238, 106, 36}, RGB{239, 108, 35}, RGB{239, 110, 33}, RGB{240, 111, 32},
    RGB{241, 113, 31}, RGB{241, 115, 29}, RGB{242, 116, 28}, RGB{243, 118, 27},
    RGB{243, 120, 25}, RGB{244, 121, 24}, RGB{245, 123, 23}, RGB{245, 125, 21},
    RGB{246, 126, 20}, RGB{246, 128, 19}, RGB{247, 130, 18}, RGB{247, 132, 16},
    RGB{248, 133, 15}, RGB{248, 135, 14}, RGB{248, 137, 12}, RGB{249, 139, 11},
    RGB{249, 140, 10}, RGB{249, 142, 9}, RGB{250, 144, 8}, RGB{250, 146, 7},
    RGB{250, 148, 7}, RGB{251, 150, 6}, RGB{251, 151, 6}, RGB{251, 153, 6},
    RGB{251, 155, 6}, RGB{251, 157, 7}, RGB{252, 159, 7}, RGB{252, 161, 8},
    RGB{252, 163, 9}, RGB{252, 165, 10}, RGB{252, 166, 12}, RGB{252, 168, 13},
    RGB{252, 170, 15}, RGB{252, 172, 17}, RGB{252, 174, 18}, RGB{252, 176, 20},
    RGB{252, 178, 22}, RGB{252, 180, 24}, RGB{251, 182, 26}, RGB{251, 184, 29},
    RGB{251, 186, 31}, RGB{251, 188, 33}, RGB{251, 190, 35}, RGB{250, 192, 38},
    RGB{250, 194, 40}, RGB{250, 196, 42}, RGB{250, 198, 45}, RGB{249, 199, 47},
    RGB{249, 201, 50}, RGB{249, 203, 53}, RGB{248, 205, 55}, RGB{248, 207, 58},
    RGB{247, 209, 61}, RGB{247, 211, 64}, RGB{246, 213, 67}, RGB{246, 215, 70},
    RGB{245, 217, 73}, RGB{245, 219, 76}, RGB{244, 221, 79}, RGB{244, 223, 83},
    RGB{244, 225, 86}, RGB{243, 227, 90}, RGB{243, 229, 93}, RGB{242, 230, 97},
    RGB{242, 232, 101}, RGB{242, 234, 105}, RGB{241, 236, 109},
    RGB{241, 237, 113}, RGB{241, 239, 117}, RGB{241, 241, 121},
    RGB{242, 242, 125}, RGB{242, 244, 130}, RGB{243, 245, 134},
    RGB{243, 246, 138}, RGB{244, 248, 142}, RGB{245, 249, 146},
    RGB{246, 250, 150}, RGB{248, 251, 154}, RGB{249, 252, 157},
    RGB{250, 253, 161}, RGB{252, 255, 164});

export inline constexpr auto plasma = array_of<RGB>(
    RGB{13, 8, 135}, RGB{16, 7, 136}, RGB{19, 7, 137}, RGB{22, 7, 138},
    RGB{25, 6, 140}, RGB{27, 6, 141}, RGB{29, 6, 142}, RGB{32, 6, 143},
    RGB{34, 6, 144}, RGB{36, 6, 145}, RGB{38, 5, 145}, RGB{40, 5, 146},
    RGB{42, 5, 147}, RGB{44, 5, 148}, RGB{46, 5, 149}, RGB{47, 5, 150},
    RGB{49, 5, 151}, RGB{51, 5, 151}, RGB{53, 4, 152}, RGB{55, 4, 153},
    RGB{56, 4, 154}, RGB{58, 4, 154}, RGB{60, 4, 155}, RGB{62, 4, 156},
    RGB{63, 4, 156}, RGB{65, 4, 157}, RGB{67, 3, 158}, RGB{68, 3, 158},
    RGB{70, 3, 159}, RGB{72, 3, 159}, RGB{73, 3, 160}, RGB{75, 3, 161},
    RGB{76, 2, 161}, RGB{78, 2, 162}, RGB{80, 2, 162}, RGB{81, 2, 163},
    RGB{83, 2, 163}, RGB{85, 2, 164}, RGB{86, 1, 164}, RGB{88, 1, 164},
    RGB{89, 1, 165}, RGB{91, 1, 165}, RGB{92, 1, 166}, RGB{94, 1, 166},
    RGB{96, 1, 166}, RGB{97, 0, 167}, RGB{99, 0, 167}, RGB{100, 0, 167},
    RGB{102, 0, 167}, RGB{103, 0, 168}, RGB{105, 0, 168}, RGB{106, 0, 168},
    RGB{108, 0, 168}, RGB{110, 0, 168}, RGB{111, 0, 168}, RGB{113, 0, 168},
    RGB{114, 1, 168}, RGB{116, 1, 168}, RGB{117, 1, 168}, RGB{119, 1, 168},
    RGB{120, 1, 168}, RGB{122, 2, 168}, RGB{123, 2, 168}, RGB{125, 3, 168},
    RGB{126, 3, 168}, RGB{128, 4, 168}, RGB{129, 4, 167}, RGB{131, 5, 167},
    RGB{132, 5, 167}, RGB{134, 6, 166}, RGB{135, 7, 166}, RGB{136, 8, 166},
    RGB{138, 9, 165}, RGB{139, 10, 165}, RGB{141, 11, 165}, RGB{142, 12, 164},
    RGB{143, 13, 164}, RGB{145, 14, 163}, RGB{146, 15, 163}, RGB{148, 16, 162},
    RGB{149, 17, 161}, RGB{150, 19, 161}, RGB{152, 20, 160}, RGB{153, 21, 159},
    RGB{154, 22, 159}, RGB{156, 23, 158}, RGB{157, 24, 157}, RGB{158, 25, 157},
    RGB{160, 26, 156}, RGB{161, 27, 155}, RGB{162, 29, 154}, RGB{163, 30, 154},
    RGB{165, 31, 153}, RGB{166, 32, 152}, RGB{167, 33, 151}, RGB{168, 34, 150},
    RGB{170, 35, 149}, RGB{171, 36, 148}, RGB{172, 38, 148}, RGB{173, 39, 147},
    RGB{174, 40, 146}, RGB{176, 41, 145}, RGB{177, 42, 144}, RGB{178, 43, 143},
    RGB{179, 44, 142}, RGB{180, 46, 141}, RGB{181, 47, 140}, RGB{182, 48, 139},
    RGB{183, 49, 138}, RGB{184, 50, 137}, RGB{186, 51, 136}, RGB{187, 52, 136},
    RGB{188, 53, 135}, RGB{189, 55, 134}, RGB{190, 56, 133}, RGB{191, 57, 132},
    RGB{192, 58, 131}, RGB{193, 59, 130}, RGB{194, 60, 129}, RGB{195, 61, 128},
    RGB{196, 62, 127}, RGB{197, 64, 126}, RGB{198, 65, 125}, RGB{199, 66, 124},
    RGB{200, 67, 123}, RGB{201, 68, 122}, RGB{202, 69, 122}, RGB{203, 70, 121},
    RGB{204, 71, 120}, RGB{204, 73, 119}, RGB{205, 74, 118}, RGB{206, 75, 117},
    RGB{207, 76, 116}, RGB{208, 77, 115}, RGB{209, 78, 114}, RGB{210, 79, 113},
    RGB{211, 81, 113}, RGB{212, 82, 112}, RGB{213, 83, 111}, RGB{213, 84, 110},
    RGB{214, 85, 109}, RGB{215, 86, 108}, RGB{216, 87, 107}, RGB{217, 88, 106},
    RGB{218, 90, 106}, RGB{218, 91, 105}, RGB{219, 92, 104}, RGB{220, 93, 103},
    RGB{221, 94, 102}, RGB{222, 95, 101}, RGB{222, 97, 100}, RGB{223, 98, 99},
    RGB{224, 99, 99}, RGB{225, 100, 98}, RGB{226, 101, 97}, RGB{226, 102, 96},
    RGB{227, 104, 95}, RGB{228, 105, 94}, RGB{229, 106, 93}, RGB{229, 107, 93},
    RGB{230, 108, 92}, RGB{231, 110, 91}, RGB{231, 111, 90}, RGB{232, 112, 89},
    RGB{233, 113, 88}, RGB{233, 114, 87}, RGB{234, 116, 87}, RGB{235, 117, 86},
    RGB{235, 118, 85}, RGB{236, 119, 84}, RGB{237, 121, 83}, RGB{237, 122, 82},
    RGB{238, 123, 81}, RGB{239, 124, 81}, RGB{239, 126, 80}, RGB{240, 127, 79},
    RGB{240, 128, 78}, RGB{241, 129, 77}, RGB{241, 131, 76}, RGB{242, 132, 75},
    RGB{243, 133, 75}, RGB{243, 135, 74}, RGB{244, 136, 73}, RGB{244, 137, 72},
    RGB{245, 139, 71}, RGB{245, 140, 70}, RGB{246, 141, 69}, RGB{246, 143, 68},
    RGB{247, 144, 68}, RGB{247, 145, 67}, RGB{247, 147, 66}, RGB{248, 148, 65},
    RGB{248, 149, 64}, RGB{249, 151, 63}, RGB{249, 152, 62}, RGB{249, 154, 62},
    RGB{250, 155, 61}, RGB{250, 156, 60}, RGB{250, 158, 59}, RGB{251, 159, 58},
    RGB{251, 161, 57}, RGB{251, 162, 56}, RGB{252, 163, 56}, RGB{252, 165, 55},
    RGB{252, 166, 54}, RGB{252, 168, 53}, RGB{252, 169, 52}, RGB{253, 171, 51},
    RGB{253, 172, 51}, RGB{253, 174, 50}, RGB{253, 175, 49}, RGB{253, 177, 48},
    RGB{253, 178, 47}, RGB{253, 180, 47}, RGB{253, 181, 46}, RGB{254, 183, 45},
    RGB{254, 184, 44}, RGB{254, 186, 44}, RGB{254, 187, 43}, RGB{254, 189, 42},
    RGB{254, 190, 42}, RGB{254, 192, 41}, RGB{253, 194, 41}, RGB{253, 195, 40},
    RGB{253, 197, 39}, RGB{253, 198, 39}, RGB{253, 200, 39}, RGB{253, 202, 38},
    RGB{253, 203, 38}, RGB{252, 205, 37}, RGB{252, 206, 37}, RGB{252, 208, 37},
    RGB{252, 210, 37}, RGB{251, 211, 36}, RGB{251, 213, 36}, RGB{251, 215, 36},
    RGB{250, 216, 36}, RGB{250, 218, 36}, RGB{249, 220, 36}, RGB{249, 221, 37},
    RGB{248, 223, 37}, RGB{248, 225, 37}, RGB{247, 226, 37}, RGB{247, 228, 37},
    RGB{246, 230, 38}, RGB{246, 232, 38}, RGB{245, 233, 38}, RGB{245, 235, 39},
    RGB{244, 237, 39}, RGB{243, 238, 39}, RGB{243, 240, 39}, RGB{242, 242, 39},
    RGB{241, 244, 38}, RGB{241, 245, 37}, RGB{240, 247, 36}, RGB{240, 249, 33});

export
    [[clang::no_destroy]] inline const std::unordered_map<std::string_view,
                                                          std::span<const RGB>>
        color_schemes{
            {std::string_view{"viridis"}, std::span{viridis}},
            {std::string_view{"magma"}, std::span{magma}},
            {std::string_view{"inferno"}, std::span{inferno}},
            {std::string_view{"plasma"}, std::span{plasma}},
        };
} // namespace colors
