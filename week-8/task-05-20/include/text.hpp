#pragma once

#include <string>

namespace text {

/**
 * Text concept.
 *
 * Attention! The idea for this example was inspired by post
 * yegor256.com/2015/02/26/composable-decorators.html. Implementation of decorator in this post
 * differs from the one given in  wikipedia.org/wiki/Decorator_pattern. The only difference is that
 * this implementation don't has extra Decorator class (which is unnecessary as for me).
 */
template <typename T>
concept Text = requires(T text) {
    { text.content() } -> std::same_as<std::string>;
};

}  // namespace text
