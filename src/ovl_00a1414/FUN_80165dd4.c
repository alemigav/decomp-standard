/* FUN_80165dd4
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80165dd4  body 0x80165dd4..0x8016623b  size 1128 B
 * body sha256 1798334af5ff7eda7e6c112b3108dadea1be929fe1df75cbd917361a8e4539df
 * provider record sha256 b526d7221f02dc4718b756d4a57eef7ee96b783a9ccacdcf2d91061952c0266b
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165dd4(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar2;
  int iVar1;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x1001f00;
    *(undefined2 *)(param_1 + 500) = 0x3c;
    *(undefined1 *)(param_1 + 0x25c) = 0;
    *(undefined1 *)(param_1 + 0x207) = 0;
    *(undefined1 *)(param_1 + 0x206) = 0;
    if ((*(ushort *)(param_1 + 0x270) & 1) != 0) {
      *(undefined1 *)(param_1 + 6) = 1;
    }
    iVar1 = 0x10;
    puVar3 = *(uint **)(param_1 + 0x234);
    do {
      iVar1 = iVar1 + -1;
      *puVar3 = *puVar3 | 0x4000;
      puVar3 = puVar3 + 0x5e;
    } while (iVar1 != 0);
    *(uint *)(*(int *)(param_1 + 0x234) + 0x5e0) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x5e0) & 0xffffbfff;
    *(uint *)(*(int *)(param_1 + 0x234) + 0x758) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x758) & 0xffffbfff;
    *(uint *)(*(int *)(param_1 + 0x234) + 0x8d0) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x8d0) & 0xffffbfff;
    *(uint *)(*(int *)(param_1 + 0x234) + 0xeb0) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0xeb0) & 0xffffbfff;
    *(uint *)(*(int *)(param_1 + 0x234) + 0x1028) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x1028) & 0xffffbfff;
    *(uint *)(*(int *)(param_1 + 0x234) + 0x11a0) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x11a0) & 0xffffbfff;
    *(uint *)(*(int *)(param_1 + 0x234) + 0x1318) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x1318) & 0xffffbfff;
    *(uint *)(*(int *)(param_1 + 0x234) + 0x1490) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x1490) & 0xffffbfff;
    *(uint *)(*(int *)(param_1 + 0x234) + 0x1608) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0x1608) & 0xffffbfff;
    iVar1 = *(int *)(param_1 + 0x234);
    *(undefined2 *)(*(int *)(iVar1 + 0x700) + 0xc) = 0;
    *(undefined2 *)(*(int *)(iVar1 + 0x700) + 0x10) = 0x1000;
    func_0x80066288(param_1);
    break;
  case 1:
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x80);
    func_0x80032b5c(param_1,0);
    if ((*(ushort *)(param_1 + 0x270) & 2) != 0) {
      *(undefined1 *)(param_1 + 6) = 2;
    }
    break;
  case 2:
    *(undefined4 *)(param_1 + 0x1e8) = 0x1f00;
    *(undefined1 *)(param_1 + 6) = 3;
  case 3:
    uVar4 = *(undefined4 *)(param_1 + 0x22c);
    uVar5 = *(undefined4 *)(param_1 + 0x230);
    func_0x800334c8(param_1,uVar4,uVar5,0);
    cVar2 = func_0x80089d54(param_1,uVar4,uVar5,0x80);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
    func_0x80032b5c(param_1,0);
    break;
  case 4:
    *(undefined4 *)(param_1 + 0x1e8) = 0x1001f00;
    *(undefined2 *)(param_1 + 500) = 0x3c;
    if ((*(ushort *)(param_1 + 0x270) & 4) != 0) {
      *(undefined1 *)(param_1 + 6) = 5;
    }
    break;
  case 5:
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x80);
    func_0x80032b5c(param_1,0);
    if ((*(ushort *)(param_1 + 0x270) & 0x10) != 0) {
      *(undefined1 *)(param_1 + 6) = 6;
      *(undefined4 *)(param_1 + 0x1e8) = 0;
      func_0x80089d54(param_1,param_2,param_3,0x80);
    }
  }
  if ((*(ushort *)(param_1 + 0x270) & 8) != 0) {
    iVar1 = *(int *)(param_1 + 0x234);
    *(short *)(*(int *)(iVar1 + 0x700) + 0x10) =
         *(short *)(*(int *)(iVar1 + 0x700) + 0x10) + *(char *)(param_1 + 0x207) * -10;
    if (*(char *)(param_1 + 0x207) < 'Z') {
      *(char *)(param_1 + 0x207) = *(char *)(param_1 + 0x207) + '\x01';
    }
    if (*(short *)(*(int *)(iVar1 + 0x700) + 0x10) < 0) {
      *(undefined2 *)(*(int *)(iVar1 + 0x700) + 0x10) = 0;
    }
    func_0x80066288(param_1,iVar1 + 0x5e0);
  }
  if ((*(ushort *)(param_1 + 0x270) & 0x20) != 0) {
    DAT_80168f4e = 0xf6;
    DAT_80168f4f = 0xe;
  }
  if ((*(ushort *)(param_1 + 0x270) & 0x40) != 0) {
    DAT_80168f4e = 0xf6;
    DAT_80168f4f = 0xf2;
  }
  if ((*(ushort *)(param_1 + 0x270) & 0x80) != 0) {
    DAT_80168f4e = 0;
    DAT_80168f4f = 0;
  }
  if ((*(ushort *)(param_1 + 0x270) & 0x100) != 0) {
    iVar1 = *(int *)(param_1 + 0x234);
    *(short *)(*(int *)(iVar1 + 0x700) + 0x10) =
         *(short *)(*(int *)(iVar1 + 0x700) + 0x10) + *(char *)(param_1 + 0x206) * 10;
    if (*(char *)(param_1 + 0x206) < 'Z') {
      *(char *)(param_1 + 0x206) = *(char *)(param_1 + 0x206) + '\x01';
    }
    if (0x1000 < *(short *)(*(int *)(iVar1 + 0x700) + 0x10)) {
      *(undefined2 *)(*(int *)(iVar1 + 0x700) + 0x10) = 0x1000;
    }
    func_0x80066288(param_1,iVar1 + 0x5e0);
  }
  *(short *)(*(int *)(*(int *)(param_1 + 0x234) + 0x298) + 0xc) =
       (char)(&DAT_80168fe8)[*(char *)(param_1 + 0x2ba)] * -5 + 0x1000;
  func_0x80066288(param_1);
  *(short *)(*(int *)(*(int *)(param_1 + 0x234) + 0x410) + 0xc) =
       (char)(&DAT_80168fe8)[*(char *)(param_1 + 0x2ba)] * -5 + 0x1000;
  func_0x80066288();
  return;
}
