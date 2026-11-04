/* FUN_8003c8d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003c8d4  body 0x8003c8d4..0x8003ce07  size 1332 B
 * body sha256 403356f526481afc7d222be3f671d8d0808da0732ffec361801b21ef60724ece
 * provider record sha256 7f252b63420b59207267fc7fc519648ddb191afc5bcbacae41a07b3161740d9d
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003c8d4(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  byte bVar10;
  int iVar11;
  int local_3c;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  puVar4 = DAT_800ebb94;
  local_30 = 0xfb500000;
  local_2c = 0x258012c;
  local_28 = 0xfda80000;
  local_24 = 0x12c0096;
  if (*(short *)(DAT_800ebb94 + 0x12) == 0) {
    uVar6 = *(undefined4 *)(DAT_800ebb94 + 0x60);
    local_3c = *(int *)(DAT_800ebb94 + 100);
    uVar7 = *(undefined4 *)(DAT_800ebb94 + 0x68);
    sVar1 = *(short *)(DAT_800ebb94 + 0x34);
    sVar2 = *(short *)(DAT_800ebb94 + 0x36);
    sVar3 = *(short *)(DAT_800ebb94 + 0x38);
    *(undefined2 *)(DAT_800ebb94 + 0x18) = 0x8000;
    *puVar4 = 0;
    *(int *)(puVar4 + 0x60) = (int)sVar1;
    puVar5 = DAT_800ebb94;
    *(undefined2 *)(puVar4 + 0x12) = 1;
    *(int *)(puVar4 + 100) = (int)sVar2;
    *(int *)(puVar4 + 0x68) = (int)sVar3;
    puVar5[1] = 0x30;
    FUN_80077adc(0x1120001,DAT_800ebb94 + 0x60);
    if ((*(ushort *)(DAT_800ebb94 + 0x18) & 0x80) == 0) {
      FUN_800609e0(DAT_800ebb94 + 0x60,(int)*(short *)(DAT_800ebb94 + 0x22),&local_30,0x2000a);
      FUN_800609e0(DAT_800ebb94 + 0x60,(int)*(short *)(DAT_800ebb94 + 0x22),&local_30,0x2000a);
      local_3c = local_3c + 0xe10;
      FUN_80038a20(0x40c2800,0,DAT_800ebb94 + 0x4c,0);
      FUN_80038a20(0x41d2700,0,DAT_800ebb94 + 0x4c,0);
      uVar8 = FUN_80033604();
      uVar9 = FUN_80033604();
      uVar8 = FUN_80038a20((uVar8 & 7) * 0x300 + 0x1c00 | 0x5050000,
                           (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + (uVar9 & 0xff) % 0x28) *
                                0x10000) >> 0x10,DAT_800ebb94 + 0x4c,0);
      if ((uVar8 & 0xff) < 0xff) {
        uVar9 = FUN_80033604();
        iVar11 = (uVar8 & 0xff) * 0x7c;
        *(ushort *)(&DAT_800ebdb4 + iVar11) =
             *(short *)(&DAT_800ebdb4 + iVar11) +
             ((short)(uVar9 & 0xff) + (short)((uVar9 & 0xff) / 0x19) * -0x19 & 0xffU);
        bVar10 = FUN_80033604();
        *(undefined2 *)(&DAT_800ebdf2 + iVar11) = 1;
        (&DAT_800ebdb1)[iVar11] = (&DAT_800ebdb1)[iVar11] + (bVar10 & 7);
      }
      uVar8 = FUN_80033604();
      uVar9 = FUN_80033604();
      uVar8 = FUN_80038a20((uVar8 & 7) * 0x300 + 0x1c00 | 0x5050000,
                           (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + (uVar9 & 0xff) % 0x50 +
                                 400) * 0x10000) >> 0x10,DAT_800ebb94 + 0x4c,0);
      if ((uVar8 & 0xff) < 0xff) {
        uVar9 = FUN_80033604();
        iVar11 = (uVar8 & 0xff) * 0x7c;
        *(ushort *)(&DAT_800ebdb4 + iVar11) =
             *(short *)(&DAT_800ebdb4 + iVar11) +
             ((short)(uVar9 & 0xff) + (short)((uVar9 & 0xff) / 0x19) * -0x19 & 0xffU);
        bVar10 = FUN_80033604();
        *(undefined2 *)(&DAT_800ebdf2 + iVar11) = 1;
        (&DAT_800ebdb1)[iVar11] = (&DAT_800ebdb1)[iVar11] + (bVar10 & 7);
      }
      uVar8 = FUN_80033604();
      uVar9 = FUN_80033604();
      uVar8 = FUN_80038a20((uVar8 & 7) * 0x300 + 0x1c00 | 0x5050000,
                           (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + (uVar9 & 0xff) % 0x50 +
                                 -400) * 0x10000) >> 0x10,DAT_800ebb94 + 0x4c,0);
      if ((uVar8 & 0xff) < 0xff) {
        uVar9 = FUN_80033604();
        iVar11 = (uVar8 & 0xff) * 0x7c;
        *(ushort *)(&DAT_800ebdb4 + iVar11) =
             *(short *)(&DAT_800ebdb4 + iVar11) +
             ((short)(uVar9 & 0xff) + (short)((uVar9 & 0xff) / 0x19) * -0x19 & 0xffU);
        bVar10 = FUN_80033604();
        *(undefined2 *)(&DAT_800ebdf2 + iVar11) = 1;
        (&DAT_800ebdb1)[iVar11] = (&DAT_800ebdb1)[iVar11] + (bVar10 & 7);
      }
    }
    else {
      FUN_800609e0(DAT_800ebb94 + 0x60,(int)*(short *)(DAT_800ebb94 + 0x22),&local_28,0x2000a);
      FUN_800609e0(DAT_800ebb94 + 0x60,(int)*(short *)(DAT_800ebb94 + 0x22),&local_28,0x2000a);
      FUN_80038a20(0x40c2800,0,DAT_800ebb94 + 0x4c,0);
      FUN_80038a20(0x41d2700,0,DAT_800ebb94 + 0x4c,0);
    }
    puVar4 = DAT_800ebb94;
    *(undefined4 *)(DAT_800ebb94 + 0x60) = uVar6;
    *(int *)(puVar4 + 100) = local_3c;
    *(undefined4 *)(puVar4 + 0x68) = uVar7;
  }
  else if (*(short *)(DAT_800ebb94 + 0x12) == 1) {
    DAT_800ebb94[1] = 0;
    *puVar4 = 0;
    *(undefined2 *)(puVar4 + 0x18) = 0;
  }
  return;
}
