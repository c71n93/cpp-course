#pragma once

#include <future>
#include <random>
#include <thread>

double pi(const size_t iterations) {
    const unsigned int available = std::thread::hardware_concurrency();
    const size_t threads = (available == 0) ? 2 : available;
    const size_t thread_iters = iterations / threads;
    std::vector<std::future<size_t>> futures;
    for (unsigned i = 0; i < threads; ++i) {
        futures.emplace_back(std::async(std::launch::async, [thread_iters] {
            size_t circle_points = 0;
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution dist(0.0, 1.0);
            for (size_t i = 0; i < thread_iters; ++i) {
                const double x = dist(gen);
                const double y = dist(gen);
                if (x * x + y * y <= 1.0) {
                    circle_points++;
                }
            }
            return circle_points;
        }));
    }
    size_t circle_points = 0;
    for (auto& f : futures) {
        circle_points += f.get();
    }
    return static_cast<double>(4 * circle_points) / static_cast<double>(iterations);
}
