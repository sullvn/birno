module;

#include <cstddef>
#include <optional>
#include <span>
#include <stdexcept>
#include <string_view>

import colors;

export module Config;

export class Config {
public:
  const std::span<const colors::RGB> color_scheme;

  /**
   * Construct from program arguments
   */
  static constexpr auto from_args(const std::span<char *> &args)
      -> std::optional<Config> {
    if (args.size() < 2) {
      return Config{.color_scheme = std::span{colors::viridis}};
    }

    if (args.size() > 2) {
      return {};
    }

    const auto color_scheme_str = args[1];
    try {
      const auto color_scheme =
          colors::color_schemes.at(std::string_view{color_scheme_str});
      return Config{.color_scheme = color_scheme};
    } catch (const std::out_of_range &) {
      return {};
    }
  }
};
