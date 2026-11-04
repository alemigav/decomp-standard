/* FUN_801640a0
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x801640a0  body 0x801640a0..0x80164193  size 244 B
 * body sha256 6021f124b00ed0f9e678f81dd02e1efea60db247b85366aca4365e4e6f202e88
 * provider record sha256 496479452d5435378618d26591b112ca3ee3f7cb0f3519952c18e9f9290a379a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801640a0(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar2;
  int iVar1;
  
  bVar2 = *(byte *)(param_1 + 6);
  if (bVar2 != 1) {
    if (1 < bVar2) {
      if ((bVar2 == 2) && (iVar1 = func_0x8008a994(param_1,param_2,param_3,0x400), iVar1 != 0)) {
        *(undefined4 *)(param_1 + 4) = 0x1040000;
      }
      goto LAB_80164150;
    }
    if (bVar2 != 0) goto LAB_80164150;
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
LAB_80164150:
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
