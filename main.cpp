#include <cstddef>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <span>

import Config;
import term_colors;

auto main(int argc, char *argv[]) -> int {
  const std::span args{argv, static_cast<std::size_t>(argc)};

  const auto maybe_config = Config::from_args(args);
  if (!maybe_config.has_value()) {
    std::cerr << "USAGE: a.out <number>\n";
    return 1;
  }

  const auto config = maybe_config.value();

  auto bytes = std::views::istream<char>(std::cin);
  auto bytes_truncated = bytes | std::views::take(config.number);

  for (const auto b : bytes_truncated) {
    const auto color =
        term_colors::set_background(255, 255, static_cast<uint8_t>(b));

    std::cout.write(color.data(), color.size());
    std::cout << " ";
    // std::cout << std::span{term_colors::set(100, 200, 0)} << b;
  }

  std::cout << term_colors::clear();
  return 0;
}
