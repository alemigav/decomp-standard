/* FUN_8007e380
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e380  body 0x8007e380..0x8007e3c7  size 72 B
 * body sha256 d44524c89c7821c20dbea33fcd1361759eebb83442d3996b3ee9ca19091aa720
 * provider record sha256 9b3598122655f5a34f2513941bfc86441128832ae352036c96f33b8c37eac84e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007e304::caseD_2(void)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  char cVar4;
  int unaff_s0;
  undefined4 uStack00000010;
  
  bVar1 = *(byte *)((int)&uStack00000010 + (int)*(char *)(unaff_s0 + 0x206));
  *(undefined1 *)(unaff_s0 + 6) = 3;
  cVar4 = *(char *)(unaff_s0 + 0x1a2) + *(char *)(unaff_s0 + 0x1f7);
  *(char *)(unaff_s0 + 0x1a2) = cVar4;
  *(uint *)(unaff_s0 + 0x1e8) = (uint)bVar1 * 0x1000000 + 0x300;
  if (*(char *)(unaff_s0 + 0x206) != '\0') {
    *(char *)(unaff_s0 + 0x1a2) = cVar4 + *(char *)(unaff_s0 + 0x1f7) * -2;
  }
  FUN_800334c8();
  iVar3 = FUN_80089d54();
  if (iVar3 != 0) {
    *(undefined1 *)(unaff_s0 + 6) = 4;
    sVar2 = *(short *)(unaff_s0 + 0x1f6);
    bVar1 = *(byte *)((int)&uStack00000010 + (int)*(char *)(unaff_s0 + 0x206));
    *(short *)(unaff_s0 + 0x1f6) = sVar2 + -1;
    *(uint *)(unaff_s0 + 0x1e8) = (bVar1 + 1) * 0x1000000;
    if (sVar2 == 1) {
      *(undefined1 *)(unaff_s0 + 6) = 5;
      *(uint *)(unaff_s0 + 0x1e8) =
           (*(byte *)((int)&uStack00000010 + (int)*(char *)(unaff_s0 + 0x206)) + 2) * 0x1000000;
    }
  }
  FUN_80032bd8();
  if ((**(uint **)(unaff_s0 + 0x214) & 0x4000) != 0) {
    FUN_80077f30(1,((**(uint **)(unaff_s0 + 0x214) & 0x2000) >> 0xd) * 3 + 4);
    DAT_800e112a = DAT_800e112a | 4;
  }
  return;
}
