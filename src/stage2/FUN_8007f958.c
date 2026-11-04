/* FUN_8007f958
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007f958  body 0x8007f958..0x8007f9af  size 88 B
 * body sha256 a8efbb39f804398438a41d690475011781503dfca4642da01c620f9cff3c5bfd
 * provider record sha256 593a8fe5f1dde84553a7e10b40253ef6a30b33fb950a19f416420a79289b76d2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007f958(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  int iVar2;
  char cVar3;
  byte bVar4;
  undefined4 uVar5;
  ushort local_10 [4];
  
  local_10[0] = 2;
  local_10[1] = 5;
  local_10[2] = 8;
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    uVar1 = local_10[*(char *)(param_1 + 0x1ed)];
    *(undefined1 *)(param_1 + 6) = 1;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xed;
    *(uint *)(param_1 + 0x1e8) = (uint)uVar1 * 0x1000000 + 0x700;
    if ((*(ushort *)(param_1 + 0x2b8) & 0x2000) != 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0x6000700;
      *(undefined1 *)(param_1 + 6) = 4;
      *(undefined4 *)(param_1 + 0x1e0) = 0;
      *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 0x12;
      if (*(short *)(param_1 + 0x1a8) == 0) {
        return;
      }
      if ((int)*(short *)(param_1 + 0x1a8) < *(short *)(param_1 + 0x25e) + -500) {
        uVar1 = local_10[*(char *)(param_1 + 0x1ed)];
        *(undefined1 *)(param_1 + 6) = 1;
        *(uint *)(param_1 + 0x1e8) = (uint)uVar1 * 0x1000000 + 0x700;
        return;
      }
      return;
    }
  case 1:
    FUN_80089d54(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),0x200);
    break;
  case 2:
    iVar2 = FUN_80032e74(param_1,DAT_800e1158,DAT_800e1160,1);
    *(undefined4 *)(param_1 + 0x1e8) = 0x9000700;
    if (iVar2 << 0x10 < 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0xb000700;
    }
    *(undefined1 *)(param_1 + 6) = 3;
    *(undefined1 *)(param_1 + 0x207) = 0;
  case 3:
    iVar2 = FUN_80089d54(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),
                         0x200);
    if ((iVar2 != 0) && (*(char *)(param_1 + 0x207) == '\0')) {
      *(undefined1 *)(param_1 + 0x207) = 1;
      *(char *)(param_1 + 0x1e8) = *(char *)(param_1 + 0x1e8) + '\x01';
    }
    break;
  case 4:
    uVar5 = 0x200;
    goto LAB_8007fb48;
  case 5:
    bVar4 = *(byte *)(param_1 + 0x25c) & 0xed;
    *(byte *)(param_1 + 0x25c) = bVar4;
    if (6000 < *(ushort *)(param_1 + 0x2ba)) {
      *(byte *)(param_1 + 0x25c) = bVar4 | 0x12;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x6000700;
    break;
  case 6:
    uVar5 = 0x10200;
LAB_8007fb48:
    cVar3 = FUN_80089d54(param_1,param_2,param_3,uVar5);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar3;
    break;
  case 7:
    *(undefined1 *)(param_1 + 6) = 0;
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xdfff;
  }
  return;
}
