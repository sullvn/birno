module;

#include <array>
#include <cstdint>
#include <format>
#include <iostream>
#include <span>
#include <string>

export module term_colors;

namespace term_colors {

/**
 * CLEAR color terminal control code
 */
constexpr std::string_view CLEAR{"\x1b[0m"};

/**
 * set_background color of terminal
 *
 * Returns terminal control code string.
 */
export constexpr auto set_background(std::uint8_t r, std::uint8_t g,
                                     std::uint8_t b) -> std::array<char, 24> {
  std::array<char, 24> buffer{};

  std::format_to(std::span{buffer}.begin(), "\x1b[48;2;{};{};{}m", r, g, b);

  return buffer;
}

/**
 * clear color of terminal
 *
 * Returns terminal control code string.
 */
export constexpr auto clear() -> std::string_view { return CLEAR; }
}; // namespace term_colors
