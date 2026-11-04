/* FUN_8009b670
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009b670  body 0x8009b670..0x8009b87f  size 528 B
 * body sha256 cd8a236cb23439f6fd6d193631ba693107beef7291d40529a19466816bf2c89d
 * provider record sha256 a87706d9b0548666aec2b6b030f92d98aa4a17ab8fb3a8cc46fda98004f37800
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8009b670(void)

{
  ushort uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  while ((DAT_800e10ec & 0x10000) != 0) {
    FUN_8004cd88(1);
  }
  FUN_8007898c();
  uVar1 = *(ushort *)(DAT_80132118 + 0x1e0);
  DAT_80132110 = 1;
  while (DAT_80114959 != '\0') {
    FUN_8009b880();
    if ((uVar1 & 0x8000) == 0) {
      FUN_8009b880();
    }
    FUN_80042af4(0);
    puVar2 = DAT_800df8b0;
    puVar3 = DAT_800df8b0 + 2;
    *DAT_800df8b0 = 0xe3001801;
    DAT_800df8b0 = puVar3;
    puVar2[1] = 0;
    puVar2 = DAT_800df8b0;
    puVar3 = DAT_800df8b0 + 2;
    *DAT_800df8b0 = 0xe3001a01;
    DAT_800df8b0 = puVar3;
    puVar2[1] = 0x10;
    FUN_8009ba38();
    if (*(ushort *)(_DAT_8013a430 + 0x22a) - 0x29 < 0xdb) {
      if (DAT_800e8c96 == 0x32) {
        FUN_8004c21c(0x20,200,&UNK_80131f20,0x4000);
      }
      if (DAT_800e8c96 == 0x34) {
        FUN_8004c21c(0x20,0xb8,&DAT_80131f37,0x4000);
        FUN_8004c21c(0x20,200,&DAT_80131f4f,0x4000);
      }
    }
    FUN_80042ad8();
    *(short *)(_DAT_8013a430 + 0x22a) = *(short *)(_DAT_8013a430 + 0x22a) + 1;
    FUN_8004cd88();
  }
  DAT_80132110 = 0;
  return;
}
