/* FUN_801638d4
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x801638d4  body 0x801638d4..0x80163bdb  size 776 B
 * body sha256 6852f5ba14d991f56f1ebc67c3a991771b535906b18219745817eb98ac8f1b5e
 * provider record sha256 55f25828317faefbef81e5e3152095743d831979ca3cd8e876725436225c060c
 * callees 12 direct (12 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801638d4(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  short sVar5;
  char cVar6;
  uint uVar4;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0xc80000;
  local_1c = 0;
  iVar2 = *(int *)(param_1 + 0x234);
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 == 1) {
LAB_801639c0:
    if (DAT_80167540 != 0) {
LAB_80163aac:
      *(undefined4 *)(param_1 + 4) = 0x10f0000;
      goto LAB_80163ab0;
    }
    DAT_80167540 = (uint)*(byte *)(param_1 + 0xc);
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined1 *)(param_1 + 0x2b6) = 1;
    *(undefined1 *)(param_1 + 0x2ce) = 3;
    *(undefined4 *)(param_1 + 0x1e8) = 0x7000300;
    *(undefined2 *)(param_1 + 6) = 0x200;
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) & 0xfffd;
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 != 0) goto LAB_80163ab0;
      *(undefined1 *)(param_1 + 7) = 0;
      if ((*(ushort *)(param_1 + 0x2c8) & 2) != 0) {
        func_0x80032dbc(param_1,*(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x28),
                        *(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x30),0x10);
        cVar6 = func_0x80036be4(param_1,6,0xf,1);
        *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar6;
        goto LAB_80163ab0;
      }
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
      goto LAB_801639c0;
    }
    if (bVar1 != 2) {
      if ((bVar1 != 3) || (*(char *)(param_1 + 0x2b6) != '\0')) goto LAB_80163ab0;
      goto LAB_80163aac;
    }
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  func_0x80032dbc(param_1,*(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x28),
                  *(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x30),8);
  iVar3 = func_0x8008a994(param_1,param_2,param_3,0x400);
  if (iVar3 != 0) {
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  func_0x80032b5c(param_1,0);
  if (*(char *)(param_1 + 0x1e9) == '\x11') {
    func_0x80037780(0x141800,0,iVar2 + 0xd70,&local_20);
    func_0x80077d18(5,param_1);
  }
LAB_80163ab0:
  cVar6 = *(char *)(param_1 + 7);
  *(char *)(param_1 + 7) = cVar6 + '\x01';
  if (((((byte)(cVar6 - 0x11U) < 8) && (*(short *)(param_1 + 500) == 0)) &&
      (iVar2 = *(int *)(param_1 + 0x2c4), *(char *)(iVar2 + 0x26f) == '\0')) &&
     ((sVar5 = func_0x80032e74(param_1,*(undefined4 *)(iVar2 + 0x28),*(undefined4 *)(iVar2 + 0x30),
                               0x100), sVar5 == 0 &&
      (*(uint *)(param_1 + 0x28c) <
       (uint)*(ushort *)(&DAT_801673d4 + (*(byte *)(param_1 + 7) - 0x11) * 2))))) {
    *(int *)(*(int *)(param_1 + 0x2c4) + 0x250) = param_1;
    *(undefined4 *)(*(int *)(param_1 + 0x2c4) + 4) = 0x2000000;
    cVar6 = func_0x80033144(param_1,0x800e1130);
    *(char *)(*(int *)(param_1 + 0x2c4) + 5) = *(char *)(*(int *)(param_1 + 0x2c4) + 5) + cVar6;
    func_0x80052bd0(3,0);
    func_0x80052d10(4,0xff,0x32,2);
    func_0x80052d10(10,0x8c,0x32,2);
    uVar4 = func_0x80059e00(0x19,0);
    if ((uVar4 & 2) != 0) {
      _DAT_800e1134 = 0x3000000;
    }
    *(undefined1 *)(param_1 + 0x2ca) = 0x28;
    *(undefined2 *)(param_1 + 500) = 1;
  }
  return;
}
