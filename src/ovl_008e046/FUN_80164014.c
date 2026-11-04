/* FUN_80164014
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80164014  body 0x80164014..0x80164107  size 244 B
 * body sha256 0de38eba8e82f8d8e9e896eecf49455c12b28dcb9775bc9984c1249136a96f6d
 * provider record sha256 a2c6c16c7f63c98e83bff76e710fcc51969526f8be59bfef3e960b4c6923cfad
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164014(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar2;
  int iVar1;
  
  bVar2 = *(byte *)(param_1 + 6);
  if (bVar2 != 1) {
    if (1 < bVar2) {
      if ((bVar2 == 2) && (iVar1 = func_0x8008a994(param_1,param_2,param_3,0x400), iVar1 != 0)) {
        *(undefined4 *)(param_1 + 4) = 0x1040000;
      }
      goto LAB_801640c4;
    }
    if (bVar2 != 0) goto LAB_801640c4;
    *(undefined4 *)(param_1 + 0x1e8) = 0x4000f00;
    *(undefined1 *)(param_1 + 0x2ce) = 3;
    *(undefined2 *)(param_1 + 6) = 0x100;
    *(undefined2 *)(param_1 + 500) = 0;
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) & 0xfffd;
  }
  iVar1 = func_0x8008a994(param_1,param_2,param_3,0x100);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x1e8) = 0x4000300;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
LAB_801640c4:
  bVar2 = *(char *)(param_1 + 7) + 1;
  *(byte *)(param_1 + 7) = bVar2;
  if (10 < bVar2) {
    iVar1 = FUN_801628a0(param_1);
    *(int *)(param_1 + 0x2c4) = iVar1;
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 4) = 0x10f0000;
    }
  }
  return;
}
