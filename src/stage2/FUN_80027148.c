/* FUN_80027148
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80027148  body 0x80027148..0x800271d3  size 140 B
 * body sha256 ec44f100c4619b5e6304acacb7451d1e11fabf14a617982cf038cf78cbe70ebf
 * provider record sha256 e0f65f3e3805ccc2094911c49450226b8cfe75d98d238998c1fef259dd7c7950
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80027148(int param_1)

{
  DAT_800e8cb0 = DAT_800e8cac;
  if (DAT_800e8cac != param_1) {
    DAT_800e8cac = (short)param_1;
    DAT_800e9183 = 1;
    DAT_800e110c = DAT_800e110c | 0x100000;
  }
  DAT_800df940 = FUN_80083cec((int)DAT_800e8cac);
  return;
}
