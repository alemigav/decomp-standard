/* FUN_8000e9d0
 * image   boot (boot), base 0x80000480
 * address 0x8000e9d0  body 0x8000e9d0..0x8000eb33  size 356 B
 * body sha256 9c3b71c9fcf87c59c64550d876a411f05a4458c33001ab2d4735f1efcc08ac36
 * provider record sha256 43bae02204eb65e5ff9aa756cfadaaa56de518692c09c9417217c98f683dbf84
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000e9d0(uint param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar3 = FUN_800072e0();
  if ((param_1 & 1) != 0) {
    *(uint *)(_DAT_800129d4 + 6) = *(uint *)(_DAT_800129d4 + 6) | 8;
  }
  if ((param_1 & 2) != 0) {
    *(uint *)(_DAT_800129d4 + 6) = *(uint *)(_DAT_800129d4 + 6) & 0xfffffff7;
  }
  if ((param_1 & 4) != 0) {
    *(uint *)(_DAT_800129d4 + 6) = *(uint *)(_DAT_800129d4 + 6) | 4;
  }
  if ((param_1 & 8) != 0) {
    *(uint *)(_DAT_800129d4 + 6) = *(uint *)(_DAT_800129d4 + 6) & 0xfffffffb;
  }
  if ((param_1 & 0x10) != 0) {
    *(uint *)(_DAT_800129d4 + 6) = *(uint *)(_DAT_800129d4 + 6) | 0x10;
  }
  if ((param_1 & 0x20) != 0) {
    *(uint *)(_DAT_800129d4 + 6) = *(uint *)(_DAT_800129d4 + 6) & 0xffffffef;
  }
  if ((param_1 & 0x40) != 0) {
    *(uint *)(_DAT_800129d4 + 6) = *(uint *)(_DAT_800129d4 + 6) & 0xfffffcff | 0x10000;
  }
  puVar2 = _DAT_800129d4;
  if ((param_1 & 0x80) != 0) {
    uVar4 = *(uint *)(_DAT_800129d4 + 6);
    puVar1 = _DAT_800129d4 + 4;
    *(uint *)(_DAT_800129d4 + 6) = uVar4 & 0xfffeffff;
    *(uint *)(puVar2 + 6) = uVar4 & 0xfffeffff | *(uint *)(*(int *)puVar1 + 4) & 0x300;
  }
  *_DAT_800129d4 = *_DAT_800129d4 | 8;
  FUN_80007300(uVar3);
  return;
}
