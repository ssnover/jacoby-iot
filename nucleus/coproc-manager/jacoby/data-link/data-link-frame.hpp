/*
 * file: data-link-frame.hpp
 * purpose: A definition of a class for containing Jacoby data-link layer payload.
 */

#ifndef DATA_LINK_FRAME_HPP
#define DATA_LINK_FRAME_HPP

struct PACKET_FRAME;

struct DATA_LINK_FRAME
{
public:
    std::array<uint8_t, 3> header {0xAA, 0xAA, 0xAA};
    PACKET_FRAME const * const payload;
    uint8_t checksum;
    std::array<uint8_t, 3> footer {0xCA, 0xCA, 0xCA};

    DATA_LINK_FRAME(PACKET_FRAME const * const _payload);
    ~DATA_LINK_FRAME() = default;
};

#endif // DATA_LINK_FRAME_HPP
