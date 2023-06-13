#include <cstddef>
#include <iostream>
#include <ranges>
#include <span>

import Config;

auto main(int argc, char *argv[]) -> int {
  std::span args{argv, static_cast<std::size_t>(argc)};

  auto maybe_config = Config::from_args(args);
  if (!maybe_config.has_value()) {
    std::cerr << "USAGE: a.out <number>\n";
    return 1;
  }

  auto config = maybe_config.value();

  auto bytes = std::views::istream<char>(std::cin);
  auto bytes_truncated = bytes | std::views::take(config.number);

  for (auto b : bytes_truncated) {
    std::cout << b << "\n";
  }
}
