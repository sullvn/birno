#include <cstddef>
#include <iostream>
#include <ranges>
#include <span>

import Config;

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
    std::cout << b << "\n";
  }

  return 0;
}
