/* FUN_80166834
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80166834  body 0x80166834..0x801669a7  size 372 B
 * body sha256 299a6082441723e6e80e1dd6fe23ba09b30f8a61fb09f2bfe7debe06a56bfb5b
 * provider record sha256 ec8321442d1b2abeb2e71dcfc6658135a0d603d5547a6628c3b60d1c2b63e8e1
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166834(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        func_0x80089d54(param_1,param_2,param_3,0x100);
        if ((*(uint *)param_1[0x85] & 0x10000) != 0) {
          *(undefined1 *)((int)param_1 + 6) = 3;
          *(undefined1 *)((int)param_1 + 0x207) = 0;
          *(undefined1 *)((int)param_1 + 0x2bd) = 1;
          func_0x80077d18(6,param_1);
        }
      }
      else if (bVar1 == 3) {
        func_0x80032bd8(param_1,0,0);
        if ((*(char *)((int)param_1 + 0x207) == '\0') &&
           (iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100), iVar2 != 0)) {
          *(undefined1 *)((int)param_1 + 0x207) = 1;
          *param_1 = *param_1 | 0x400;
        }
        if ((int)param_1[0xb] < -9000) {
          *(undefined1 *)((int)param_1 + 5) = 4;
          *(undefined2 *)((int)param_1 + 6) = 0;
        }
      }
      goto LAB_80166984;
    }
    if (bVar1 != 0) goto LAB_80166984;
    param_1[0x7a] = 0xf00;
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0xfd12;
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  if (*(short *)(param_1 + 0x9c) == 3) {
    *(undefined1 *)((int)param_1 + 6) = 2;
    param_1[0x7a] = 0xd000f00;
  }
LAB_80166984:
  FUN_80167c1c(param_1);
  return;
}
