#pragma once

#include <string>

namespace text {

/**
 * Text interface.
 *
 * Attention! The idea for this example was inspired by post
 * yegor256.com/2015/02/26/composable-decorators.html. Implementation of decorator in this post
 * differs from the one given by wikipedia.org/wiki/Decorator_pattern. The only difference is that
 * this implementation doesn't have extra Decorator class (which is unnecessary as for me).
 */
class Text {
public:
    virtual std::string content() const = 0;
    virtual ~Text() = default;
};

}  // namespace text
