/* FUN_80164890
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80164890  body 0x80164890..0x8016498b  size 252 B
 * body sha256 ce3468d0a6929ee04d6c9853498d54239f8ae0880ac502b1d9c2b7cd6974d003
 * provider record sha256 0d293b81874053cc17616a3b0575a33d395ec0bfd419fb07a6af987717c4f218
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164890(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined2 *)(param_1 + 0x270) = 0;
    *(undefined2 *)(param_1 + 0x272) = 0;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  case 1:
    if (*(short *)(param_1 + 0x270) != 0) {
      *(undefined4 *)(param_1 + 0x2c) = 0xfffff060;
      *(undefined4 *)(param_1 + 0x1e8) = 0xe330000;
      *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xbfff;
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
switchD_801648c0_caseD_2:
      *(undefined1 *)(param_1 + 0x1e8) = 0xe;
      *(undefined1 *)(param_1 + 0x1e9) = 0x33;
      func_0x80089d54(param_1,param_2,param_3,0x1000);
      iVar1 = *(int *)(param_1 + 0x2c) + 1000;
      *(int *)(param_1 + 0x2c) = iVar1;
      if (iVar1 == 0) {
        *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
      }
    }
    break;
  case 2:
    goto switchD_801648c0_caseD_2;
  case 3:
    *(undefined1 *)(param_1 + 0x1e8) = 0xe;
    cVar2 = func_0x80089d54(param_1,param_2,param_3,0x1000);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
    break;
  case 4:
    if (*(short *)(param_1 + 0x272) != 0) {
      *(undefined4 *)(param_1 + 4) = 0x1010000;
    }
  }
  return;
}
