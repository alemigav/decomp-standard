/* FUN_8003e6f0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003e6f0  body 0x8003e6f0..0x8003e9db  size 748 B
 * body sha256 32534f5578cb322ec10a1fbb934f5a1a7c27b003905a304a10ce7c580c3c180c
 * provider record sha256 160412309c345a06074ee3367e70eae6f3ace46ebe0a385075dd3725b6c7d32e
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003e6f0(void)

{
  uint uVar1;
  int iVar2;
  int unaff_s1;
  int iVar3;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0xfa880000;
  local_1c = 0x19000c8;
  DAT_80131781 = 1;
  *(char *)(DAT_800ebb94 + 2) = *(char *)(DAT_800ebb94 + 2) + -1;
  if (*(char *)(DAT_800ebb94 + 2) == '\0') {
    *(undefined1 *)(DAT_800ebb94 + 9) = 0xf6;
  }
  if (*(char *)(DAT_800ebb94 + 3) == '\0') {
    local_30 = (int)*(short *)(DAT_800ebb94 + 0x34);
    local_2c = (int)*(short *)(DAT_800ebb94 + 0x36);
    local_28 = (int)*(short *)(DAT_800ebb94 + 0x38);
    iVar3 = 0;
    iVar2 = FUN_80074d64((int)*(short *)(DAT_800ebb94 + 0x34),(int)*(short *)(DAT_800ebb94 + 0x34));
    if ((iVar2 != 0) && (iVar2 < *(short *)(DAT_800ebb94 + 0x36))) {
      iVar2 = DAT_800ebb94 + 0x34;
      iVar3 = 3;
      *(short *)(DAT_800ebb94 + 0x3a) =
           (short)(((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x41) / 100);
      FUN_80038a20(0x30f2000,0,&DAT_800e9028,iVar2);
    }
    iVar2 = FUN_800609e0(&local_30,(int)*(short *)(DAT_800ebb94 + 0x22),&local_20,0x20010);
    if (iVar2 != 0) {
      DAT_800e10fc = (int)*(short *)(DAT_800ebb94 + 0x34);
      DAT_800e1100 = (int)*(short *)(DAT_800ebb94 + 0x36);
      DAT_800e1104 = (int)*(short *)(DAT_800ebb94 + 0x38);
      iVar3 = 2;
    }
    iVar2 = FUN_80069f1c(&local_30,2,0x2000,0);
    if (iVar2 < local_2c) {
      iVar3 = 1;
    }
    if (DAT_8011270c != 0) {
      iVar3 = 1;
      *(short *)(DAT_800ebb94 + 0x3a) =
           (short)(((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 0x46) / 100);
    }
    iVar2 = DAT_800ebb94;
    if (iVar3 != 0) {
      *(undefined1 *)(DAT_800ebb94 + 8) = 0;
      iVar3 = DAT_800ebb94;
      *(undefined2 *)(iVar2 + 0xc) = 0;
      *(undefined1 *)(iVar3 + 9) = 0;
      *(undefined1 *)(DAT_800ebb94 + 0x21) = 0xc;
      *(undefined1 *)(DAT_800ebb94 + 0x20) =
           *(undefined1 *)
            (*(int *)(DAT_800ebb94 + 0x70) + (uint)*(byte *)(DAT_800ebb94 + 0x21) * 8 + 2);
      iVar2 = DAT_800ebb94;
      *(undefined2 *)(DAT_800ebb94 + 0xe) = 0x14;
      *(undefined1 *)(iVar2 + 2) = 6;
      *(undefined1 *)(DAT_800ebb94 + 3) = 1;
    }
  }
  else if ((*(char *)(DAT_800ebb94 + 2) == '\x03') &&
          (FUN_80038a20(0x40c2000,0,&DAT_800e9028,DAT_800ebb94 + 0x34), unaff_s1 == 2)) {
    uVar1 = FUN_80033604();
    FUN_80038a20(((uVar1 & 0xff) % 5) * 100 + 0x2100 | 0x5060000,0,&DAT_800e9028,DAT_800ebb94 + 0x34
                );
  }
  return;
}
