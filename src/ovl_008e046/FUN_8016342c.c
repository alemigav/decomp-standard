/* FUN_8016342c
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x8016342c  body 0x8016342c..0x801634ff  size 212 B
 * body sha256 22968fc32e08676cc25c3acee5100a5718d4fcd6acbc60f4a5cea25a397c82e2
 * provider record sha256 3d7f0c18186b2e854b7be8c460ab6b035c4f4d8b12f8a7d9901bbf02ba65c2b5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016342c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x6000f00;
    *(undefined1 *)(param_1 + 0x2ce) = 4;
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 2;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  iVar1 = *(int *)(param_1 + 0x2c4);
  if (iVar1 != 0) {
    func_0x80032dbc(param_1,*(undefined4 *)(iVar1 + 0x28),*(undefined4 *)(iVar1 + 0x30),0x20);
  }
  iVar1 = func_0x8008a994(param_1,param_2,param_3,0x10100);
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + 0x2ce) = 3;
    *(undefined4 *)(param_1 + 4) = 0x1050000;
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) & 0xfffd;
  }
  return;
}
