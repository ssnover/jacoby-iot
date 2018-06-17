/*
 * file: data-link-frame.cpp
 * purpose: Implementation of class for a Jacoby Data Link Layer frame.
 */

#include "boost/crc.hpp"
#include "packet-frame.hpp"
#include "data-link-frame.hpp"

namespace
{
boost::crc_optimal<8, 0xB6, 0xFF, 0, false, false> const CHECKSUM_SOLVER;
} // anonymous namespace


DATA_LINK_FRAME::DATA_LINK_FRAME(PACKET_FRAME const * const _payload) : payload(_payload)
{
    CHECKSUM_SOLVER.process_byte(this->payload.header);
    CHECKSUM_SOLVER.process_bytes(this->payload.payload, this->payload.header.length);
    this->checksum = CHECKSUM_SOLVER.checksum();
}