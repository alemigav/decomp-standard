/* FUN_8016237c
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x8016237c  body 0x8016237c..0x8016257b  size 512 B
 * body sha256 4d8595dee6359b33c804652aae6d6aa5c9374f9e5ea714f99b6cfe02ee750e9b
 * provider record sha256 f88bb6f17d2b0c2283acaf23c662628758329baf1fe1c33f5989bbac79df6c55
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8016237c(int param_1)

{
  int iVar1;
  char cVar3;
  uint uVar2;
  int iVar4;
  undefined4 *puVar5;
  
  iVar1 = *(int *)(param_1 + 0x234);
  puVar5 = (undefined4 *)(iVar1 + 0x2050);
  switch(*(undefined1 *)(param_1 + 0x2b6)) {
  default:
    goto switchD_801623b8_caseD_0;
  case 1:
    *(undefined1 *)(param_1 + 0x2dc) = 0;
    *(char *)(param_1 + 0x2b6) = *(char *)(param_1 + 0x2b6) + '\x01';
  case 2:
    cVar3 = *(char *)(param_1 + 0x2dc) + '\x01';
    *(char *)(param_1 + 0x2dc) = cVar3;
    if (cVar3 != '\x11') {
      return 0;
    }
    cVar3 = *(char *)(param_1 + 0x2b6) + '\x01';
    break;
  case 3:
    *puVar5 = 1;
    *(short *)(*(int *)(iVar1 + 0x2170) + 0xc) = *(short *)(*(int *)(iVar1 + 0x2170) + 0xc) + 0x800;
    func_0x80066288(param_1,puVar5);
    if (*(short *)(*(int *)(iVar1 + 0x2170) + 0xc) < 0x1000) {
      return 0;
    }
    cVar3 = *(char *)(param_1 + 0x2b6) + '\x01';
    break;
  case 4:
    *(short *)(*(int *)(iVar1 + 0x2170) + 0x10) =
         *(short *)(*(int *)(iVar1 + 0x2170) + 0x10) + 0x400;
    func_0x80066288(param_1,puVar5);
    if (*(short *)(*(int *)(iVar1 + 0x2170) + 0x10) < 0x1000) {
      return 0;
    }
    *(undefined1 *)(param_1 + 0x2dc) = 4;
    cVar3 = *(char *)(param_1 + 0x2b6) + '\x01';
    break;
  case 5:
    iVar4 = (uint)*(byte *)(param_1 + 0x2dc) * 4 + *(int *)(iVar1 + 0x2170);
    *(short *)(iVar4 + 4) = *(short *)(iVar4 + 4) + 0x1000;
    func_0x80066288(param_1,puVar5);
    uVar2 = *(byte *)(param_1 + 0x2dc) + 1;
    if (*(short *)((uint)*(byte *)(param_1 + 0x2dc) * 4 + *(int *)(iVar1 + 0x2170) + 4) < 0x1000) {
      return 0;
    }
    *(char *)(param_1 + 0x2dc) = (char)uVar2;
    if ((uVar2 & 0xff) == 0xb) {
      *(char *)(param_1 + 0x2b6) = *(char *)(param_1 + 0x2b6) + '\x01';
      *(undefined2 *)(*(int *)(iVar1 + 0x2170) + 0xc) = 0;
      *(undefined2 *)(*(int *)(iVar1 + 0x2170) + 0x10) = 0;
      *(undefined2 *)(*(int *)(iVar1 + 0x2170) + 0x14) = 0;
      *(undefined2 *)(*(int *)(iVar1 + 0x2170) + 0x18) = 0;
      *(undefined2 *)(*(int *)(iVar1 + 0x2170) + 0x1c) = 0;
      *(undefined2 *)(*(int *)(iVar1 + 0x2170) + 0x20) = 0;
      *(undefined2 *)(*(int *)(iVar1 + 0x2170) + 0x24) = 0;
      *(undefined2 *)(*(int *)(iVar1 + 0x2170) + 0x28) = 0;
      return 0;
    }
    return 0;
  case 6:
    *(short *)(*(int *)(iVar1 + 0x2170) + 0x2c) =
         *(short *)(*(int *)(iVar1 + 0x2170) + 0x2c) + -0x1000;
    func_0x80066288(param_1,puVar5);
    if (*(short *)(*(int *)(iVar1 + 0x2170) + 0x2c) < 1) {
      *(undefined1 *)(param_1 + 0x2b6) = 0;
      DAT_80167540 = 0;
      *puVar5 = 0;
    }
    goto switchD_801623b8_caseD_0;
  }
  *(char *)(param_1 + 0x2b6) = cVar3;
switchD_801623b8_caseD_0:
  return 0;
}
