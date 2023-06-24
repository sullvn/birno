#include <cstddef>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <span>

import colors;
import Config;
import term_colors;

/**
 * print_usage information to stderr
 */
static auto print_usage() -> void {
  const auto color_scheme_names = colors::color_schemes | std::views::keys;

  std::cerr << "USAGE: birno <";

  bool first = true;
  for (const auto &csn : color_scheme_names) {
    if (!first) {
      std::cerr << " | ";
    }
    std::cerr << csn;

    first = false;
  }

  std::cerr << ">\n";
}

auto main(int argc, char *argv[]) -> int {
  const std::span args{argv, static_cast<std::size_t>(argc)};

  const auto maybe_config = Config::from_args(args);
  if (!maybe_config.has_value()) {
    print_usage();
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
