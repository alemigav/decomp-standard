/* FUN_80162d04
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80162d04  body 0x80162d04..0x80162e0f  size 268 B
 * body sha256 c522fa523816864134dac1c07d1aed23237e8b8839b3273298a23ff7d72b1665
 * provider record sha256 4443d210a2a82bde27c1d42c8d4408fd865181b66887492a86c833c7b4255278
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162d04(int param_1)

{
  ushort *puVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x234);
  if (*(char *)(param_1 + 0x2cf) == '\0') {
    DAT_80167530 = &DAT_80167314;
    *(code **)(param_1 + 0x2d8) = FUN_80162d04;
    *(char *)(param_1 + 0x2cf) = *(char *)(param_1 + 0x2cf) + '\x01';
  }
  else {
    do {
      if ((*(ushort *)(DAT_80167530 + 10) & 2) == 0) {
        uVar2 = *(ushort *)(DAT_80167530 + 8);
        uVar3 = func_0x80033604();
        func_0x80037780((uVar3 & 0xff) * 2 + 0x1000 | 0x6000000,0,iVar4 + (uint)uVar2 * 0x178 + 0x38
                        ,DAT_80167530);
      }
      puVar1 = (ushort *)(DAT_80167530 + 10);
      DAT_80167530 = DAT_80167530 + 0xc;
    } while ((*puVar1 & 1) != 0);
    if (*(char *)(param_1 + 0x2cf) == '\x10') {
      *(undefined4 *)(param_1 + 0x2d8) = 0;
    }
    *(char *)(param_1 + 0x2cf) = *(char *)(param_1 + 0x2cf) + '\x01';
  }
  return;
}
