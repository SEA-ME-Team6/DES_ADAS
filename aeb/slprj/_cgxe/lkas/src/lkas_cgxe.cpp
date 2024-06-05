/* Include files */

#include "lkas_cgxe.hpp"
#include "m_bWZtXix408x4Us1rl4Tg2.hpp"

unsigned int cgxe_lkas_method_dispatcher(SimStruct* S, int_T method, void* data)
{
  if (ssGetChecksum0(S) == 3448200763 &&
      ssGetChecksum1(S) == 1903402774 &&
      ssGetChecksum2(S) == 1811703623 &&
      ssGetChecksum3(S) == 4204856523) {
    method_dispatcher_bWZtXix408x4Us1rl4Tg2(S, method, data);
    return 1;
  }

  return 0;
}
