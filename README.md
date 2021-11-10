# Space-Saving
Space Saving Algorithm C++ Implementation Using Min-heap

## Incentive
* Inspired by an Amazon Tech Talk: http://romania.amazon.com/techon/presentations/DataStreamsAlgorithms_FlorinManolache.pdf, this algorithm with using min-heap supports weighted items and improves the worst-case running time from linear to logarithmic. 

## SampleData.txt
* Input sequence: a, b, a, c, d, e, a, d, f, a, d
* Expected SpaceSaving Summary: a(4), d(3), e(2), f(2)

## zipfData.txt
* 1e5 data in zipf distribution
* Running time is approximately 800 nanoseconds

## Reference
* A. Metwally, D. Agrawal, and A. El Abbadi. Efficient Computation of Frequent and Top-k Elements in Data Streams. In Proceedings of the 10th ICDT International Conference on Database Theory, pages 398–412, 2005.
