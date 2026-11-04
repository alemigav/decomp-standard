/* osCreateThread
 * image   boot (boot), base 0x80000480
 * address 0x80006d60  body 0x80006d60..0x80006e2f  size 208 B
 * body sha256 aacfeeb116fd142c7360ac60fbe6350ae01a7e5e77a4ea144b63e9bbbd207f0e
 * provider record sha256 ddd3595f268f3dbc36d88cb02969e35bdce06a4184d0ab5373e7d24adc7d25c7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void osCreateThread(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,
                   int param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  param_1[0x40] = 0xffffffff;
  param_1[0x41] = &DAT_8000116c;
  param_1[0x46] = 0xff03;
  param_1[0x4a] = 0x3f;
  param_1[5] = param_2;
  *param_1 = 0;
  param_1[2] = 0;
  param_1[0x47] = param_3;
  param_1[0xe] = param_4 >> 0x1f;
  param_1[0xf] = param_4;
  param_1[0x4b] = 0x1000800;
  param_1[6] = 0;
  *(undefined2 *)(param_1 + 4) = 1;
  *(undefined2 *)((int)param_1 + 0x12) = 0;
  param_1[1] = param_6;
  param_1[0x3c] = (param_5 >> 0x1f) + -1 + (uint)(param_5 - 0x10U < 0xfffffff0);
  param_1[0x3d] = param_5 - 0x10U;
  uVar2 = FUN_800072e0();
  puVar1 = param_1;
  param_1[3] = _DAT_8001294c;
  _DAT_8001294c = puVar1;
  FUN_80007300(uVar2);
  return;
}
