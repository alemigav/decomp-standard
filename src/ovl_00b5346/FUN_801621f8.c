/* FUN_801621f8
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x801621f8  body 0x801621f8..0x80162407  size 528 B
 * body sha256 a859134319a74e6990f4c8bf8af19f43d12dae57e05c2ad7a9841c9b6d4878ab
 * provider record sha256 2829fe13a24f07958ca5d0e1fae3af6a92dbe24bb01cc3f4287b8ba7dd65e15f
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801621f8(int param_1,undefined4 param_2,undefined4 param_3,short param_4)

{
  byte bVar1;
  short sVar2;
  char cVar5;
  int iVar3;
  uint uVar4;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_28 = _DAT_800e1158;
  local_20 = _DAT_800e1160;
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        local_24 = 0;
        func_0x800653d0(param_1,&local_28,0,0);
        param_4 = func_0x80032e74(param_1,(int)*(short *)(param_1 + 0x260),
                                  (int)*(short *)(param_1 + 0x262),2);
        sVar2 = *(short *)(param_1 + 500);
        *(short *)(param_1 + 500) = sVar2 + -1;
        if (sVar2 == 1) {
          *(undefined1 *)(param_1 + 7) = 1;
        }
      }
      goto LAB_80162300;
    }
    if (bVar1 != 0) goto LAB_80162300;
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined2 *)(param_1 + 0x1e0) = 2;
    cVar5 = func_0x80033604();
    *(byte *)(param_1 + 0x206) = cVar5 + 1U & 7;
  }
  param_4 = 0;
  if (*(char *)(param_1 + 0x206) == '\0') {
    param_4 = func_0x80032e74(param_1,local_28,local_20,2);
    *(undefined1 *)(param_1 + 0x206) = 4;
  }
LAB_80162300:
  *(char *)(param_1 + 0x206) = *(char *)(param_1 + 0x206) + -1;
  if (*(char *)(param_1 + 0x2b8) != '\0') {
    param_4 = -param_4;
  }
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + param_4;
  func_0x80032b5c(param_1,0);
  if ((((*(char *)(param_1 + 0x2b8) == '\0') && ((_DAT_800e1128 & 0x10) == 0)) &&
      (iVar3 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x100), iVar3 == 0)) &&
     ((*(uint *)(param_1 + 0x28c) < 0x708 &&
      (uVar4 = func_0x80033604(param_1,param_2), (0x27e4 >> (uVar4 & 0xf) & 1U) != 0)))) {
    _DAT_800e1128 = _DAT_800e1128 | 0x10;
    *(undefined1 *)(param_1 + 0x2b8) = 0x5a;
    *(undefined2 *)(param_1 + 6) = 0x100;
  }
  func_0x80089d54(param_1,param_2,param_3,0x80);
  return;
}
