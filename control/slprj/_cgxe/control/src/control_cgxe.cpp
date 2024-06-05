/* Include files */

#include "control_cgxe.hpp"
#include "m_VeCx0ydmw8JKSFocOvsFrF.hpp"
#include "m_XIuNdPJVc2X6cBQjZkByfD.hpp"

unsigned int cgxe_control_method_dispatcher(SimStruct* S, int_T method, void
  * data)
{
  if (ssGetChecksum0(S) == 3361987588 &&
      ssGetChecksum1(S) == 1553610314 &&
      ssGetChecksum2(S) == 2340632505 &&
      ssGetChecksum3(S) == 2086068362) {
    method_dispatcher_VeCx0ydmw8JKSFocOvsFrF(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 4245158246 &&
      ssGetChecksum1(S) == 2922654843 &&
      ssGetChecksum2(S) == 143298938 &&
      ssGetChecksum3(S) == 2383791522) {
    method_dispatcher_XIuNdPJVc2X6cBQjZkByfD(S, method, data);
    return 1;
  }

  return 0;
}
