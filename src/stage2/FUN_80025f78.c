/* FUN_80025f78
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80025f78  body 0x80025f78..0x8002603f  size 200 B
 * body sha256 13e6968337357557544addc518a5d1bf0cbe43458f74b827db256a49ddd3cd53
 * provider record sha256 efa7f06684a5277ade225f7a96baed9358755f0ffaf35476d87e0122b3e32e6f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80025f78(short param_1,short param_2,int param_3)

{
  undefined4 uVar1;
  undefined1 uVar2;
  undefined *puVar3;
  
  if (param_1 == 0) {
    puVar3 = &DAT_800c4eb8;
    DAT_800c4f34 = *(undefined4 *)(param_3 + 0x18);
    DAT_800c56e8 = *(undefined4 *)(param_3 + 0x14);
  }
  else {
    puVar3 = &DAT_800c4f08;
    DAT_800c4f4c = *(undefined4 *)(param_3 + 0x18);
  }
  uVar1 = *(undefined4 *)(param_3 + 0x14);
  puVar3[0x16] = (char)param_2;
  *(undefined4 *)(puVar3 + 0x10) = uVar1;
  if (param_2 == 0) {
    uVar2 = 2;
  }
  else {
    if (param_2 != 2) {
      DAT_800c4eba = 0x500;
      DAT_800c4ebe = 0x500;
      DAT_800c4ec2 = 0x3c0;
      DAT_800c4ec6 = 0x3c0;
      DAT_800c4ed4 = 0x400;
      DAT_800c4ed6 = 0x400;
      DAT_800c4ed8 = 0;
      DAT_800c4f0a = 0x500;
      DAT_800c4f0e = 0x500;
      DAT_800c4f12 = 0x3c0;
      DAT_800c4f16 = 0x3c0;
      DAT_800c4f24 = 0x400;
      DAT_800c4f26 = 0x400;
      DAT_800c4f28 = 0;
      return;
    }
    uVar2 = 1;
  }
  puVar3[0x17] = uVar2;
  DAT_800c4f26 = 0x400;
  DAT_800c4ed6 = 0x400;
  DAT_800c4f24 = 0x400;
  DAT_800c4ed4 = 0x400;
  DAT_800c4f28 = 0;
  DAT_800c4ed8 = 0;
  DAT_800c4f0a = 0x500;
  DAT_800c4eba = 0x500;
  DAT_800c4f16 = 0x3c0;
  DAT_800c4ec6 = 0x3c0;
  DAT_800c4f12 = 0x3c0;
  DAT_800c4ec2 = 0x3c0;
  DAT_800c4f0e = 0x500;
  DAT_800c4ebe = 0x500;
  return;
}
