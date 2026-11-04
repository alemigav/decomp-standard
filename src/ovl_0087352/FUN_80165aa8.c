/* FUN_80165aa8
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80165aa8  body 0x80165aa8..0x80165bc3  size 284 B
 * body sha256 0786a5baaf5e7f556bb7c8bfe43e0db61b27ec34ec0d599fbea68f0fc4a6446e
 * provider record sha256 0dd11e618d8d4ea3fd4429e85b1a8b4ed05d2ba1d48e8d2fd3a73968763b3a4b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165aa8(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)((int)param_1 + 0x26f) = 0x80;
    param_1[0x7a] = 0xb000700;
    *param_1 = *param_1 | 2;
    func_0x800341dc(param_1[0x82],_DAT_800c76b0);
    *(undefined2 *)(param_1[0x82] + 4) = 400;
    *(undefined2 *)(param_1[0x82] + 6) = 400;
    *(undefined2 *)((int)param_1 + 0x1f6) = 0x3c;
    *(undefined1 *)((int)param_1 + 0x2b5) = 0xb;
    *(undefined1 *)((int)param_1 + 6) = 1;
  }
  if (*(char *)((int)param_1 + 0x2b5) != '\0') {
    *(char *)((int)param_1 + 0x2b5) = *(char *)((int)param_1 + 0x2b5) + -1;
    func_0x80089d54(param_1,param_2,param_3,0x200);
  }
  if (*(short *)((int)param_1 + 0x1f6) == 0) {
    *(undefined1 *)((int)param_1 + 6) = 2;
  }
  else {
    *(short *)((int)param_1 + 0x1f6) = *(short *)((int)param_1 + 0x1f6) + -1;
    *(short *)(param_1[0x82] + 4) = *(short *)(param_1[0x82] + 4) + 10;
    *(short *)(param_1[0x82] + 6) = *(short *)(param_1[0x82] + 6) + 10;
  }
  return;
}
