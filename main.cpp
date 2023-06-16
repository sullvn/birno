#include <cstddef>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <span>

import colors;
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
  for (const auto b : bytes) {
    const auto color =
        colors::byte_color(config.color_scheme, static_cast<std::byte>(b));
    const auto color_tty =
        term_colors::set_background(color.r, color.g, color.b);

    std::cout.write(color_tty.data(), color_tty.size());
    std::cout << " ";
  }

  std::cout << term_colors::clear();
  return 0;
}
