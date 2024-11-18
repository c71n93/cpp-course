#pragma once

#include <string>

namespace text {

/**
 * Concept for Text.
 *
 * Attention! The idea for this example was inspired by post
 * yegor256.com/2015/02/26/composable-decorators.html. Implementation of decorator in this post
 * differs from the one given by wikipedia.org/wiki/Decorator_pattern. The only difference is that
 * this implementation doesn't have extra Decorator class (which is unnecessary as for me).
 *
 * Also, we don't have inheritance at all in this template implementation. I think it's not
 * necessary here, because these decorators are used at compile time. And at compile time,
 * polymorphism is implemented using templates that can be constrained using concepts (Text in our
 * case).
 */
template <typename T>
concept Text = requires(T text) {
    { text.content() } -> std::same_as<std::string>;
};

}  // namespace text
