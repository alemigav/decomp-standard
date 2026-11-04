/* FUN_801634c0
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x801634c0  body 0x801634c0..0x80163607  size 328 B
 * body sha256 22129e99f3b567363656535635c4b370d44a4f748e995568a46ce307ccda50df
 * provider record sha256 7e4342bdb14a7e6023faa949f1ebd42aa1c9986d381ae284f3feb4245d801d0c
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801634c0(uint *param_1)

{
  short sVar1;
  
  _DAT_800df9b4 = FUN_80165758;
  param_1[1] = 0x1080000;
  param_1[0x7a] = 0;
  func_0x80089d54();
  *(undefined1 *)((int)param_1 + 0x25d) = 5;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  *param_1 = *param_1 | 0x1c000000;
  if ((_DAT_800e10ec & 0x20) == 0) {
    sVar1 = 200;
  }
  else {
    sVar1 = 0xfa;
  }
  *(short *)((int)param_1 + 0x1f2) = sVar1 + 20000;
  *(undefined2 *)(param_1 + 0xae) = 2;
  param_1[0xa1] = 1;
  *(undefined2 *)(param_1 + 0x4d) = 0xf8f8;
  *(undefined2 *)((int)param_1 + 0x13a) = 0x708;
  *(undefined1 *)((int)param_1 + 0x2ba) = 0;
  *(undefined1 *)(param_1 + 0xb1) = 0;
  *(undefined1 *)((int)param_1 + 0x2c5) = 0;
  param_1[0xaf] = 0;
  param_1[0xb0] = 0;
  *(undefined1 *)((int)param_1 + 0x2c6) = 0;
  *(undefined2 *)(param_1 + 0xb4) = 0;
  *(undefined1 *)((int)param_1 + 0x2d2) = 0;
  *(undefined2 *)(param_1 + 0x9c) = 0;
  *(undefined2 *)((int)param_1 + 0x272) = 0;
  *(undefined2 *)(param_1 + 0x9d) = 0;
  *(undefined2 *)((int)param_1 + 0x276) = 0;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  *(undefined2 *)(param_1 + 0x4b) = 1000;
  *(undefined2 *)((int)param_1 + 0x136) = 1000;
  *(undefined2 *)((int)param_1 + 0x12e) = 1000;
  *(undefined2 *)(param_1 + 0x4e) = 1000;
  *(undefined2 *)((int)param_1 + 0x28a) = 800;
  FUN_80162edc(param_1);
  func_0x800339dc(param_1 + 0x82,0,0x2ee0226,0,param_1 + 10);
  return;
}
