/* FUN_8007efe8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007efe8  body 0x8007efe8..0x8007f0e7  size 256 B
 * body sha256 64f93adabda1fb8016069c18438ec0a0d5343346ef1afbc905555ad54683741c
 * provider record sha256 0d8713ac91a3b35615e8a88b999182642c5a68c4d06218646292769b70898f9c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007efe8(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar3;
  ushort uVar2;
  ushort uVar4;
  
  FUN_800807cc();
  cVar3 = DAT_8011af7f + -1;
  if (DAT_8011af7f == '\0') {
    bVar1 = *(byte *)(param_1 + 0x1ab);
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xff00;
    uVar2 = FUN_80080af4(param_1,3000);
    uVar4 = *(ushort *)(param_1 + 0x2b8);
    uVar2 = *(ushort *)(param_1 + 0x1aa) | uVar2;
    *(ushort *)(param_1 + 0x1aa) = uVar2;
    *(ushort *)(param_1 + 0x2b8) = uVar4 & 0x7fff;
    if ((bVar1 & 0xf) != (uVar2 & 0xf)) {
      uVar4 = uVar4 & 0x7ffc;
      *(ushort *)(param_1 + 0x2b8) = uVar4;
      *(ushort *)(param_1 + 0x2b8) =
           uVar4 | (byte)(&DAT_8011b2d8)[*(ushort *)(param_1 + 0x1aa) & 0xf] | 0x8000;
    }
    cVar3 = '\x0f';
  }
  DAT_8011af7f = cVar3;
  (*(code *)(&PTR_FUN_8011b2ac)[*(ushort *)(param_1 + 0x1aa) & 0xf])(param_1,param_2,param_3);
  return;
}
