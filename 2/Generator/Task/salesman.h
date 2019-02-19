#pragma once


typedef unsigned int uint;

namespace Generator
{
namespace Constants
{
    const unsigned int infinity = 0xFFFFFFFF;
} // namespace Constants
namespace Task
{
    int salesman(int n, const uint *d, uint *r);
} // namespace Salesman
} // namespace Generator
