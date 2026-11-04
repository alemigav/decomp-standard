/* FUN_8003e9dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003e9dc  body 0x8003e9dc..0x8003eb97  size 444 B
 * body sha256 5c0ef513f5e8418ca6a593786bc7a0e3daccd9e8a59ba2dbb8b86f058edc08f1
 * provider record sha256 1bb4a1032df4388d2da66aa45b403d6d1844e7cabc8e6c0ddd34853ee08351c0
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003e9dc(void)

{
  bool bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int local_30;
  int local_2c;
  int local_28;
  
  FUN_80039ba8();
  puVar2 = DAT_800ebb94;
  uVar8 = 2;
  do {
    if ((uVar8 & 3) == 0) {
      uVar5 = FUN_80038a20(*(ushort *)(puVar2 + 0x3a) | 0x1c020000,(int)*(short *)(puVar2 + 0x22),
                           &DAT_800e9028,puVar2 + 0x2c);
      if ((uVar5 & 0xff) < 0xff) {
        DAT_800ebb94 = &DAT_800ebda8 + (uVar5 & 0xff) * 0x7c;
        uVar5 = uVar8;
        do {
          FUN_8003954c(1);
          puVar3 = DAT_800ebb94;
          uVar5 = uVar5 - 1;
          *(undefined2 *)(DAT_800ebb94 + 0x12) = 0;
        } while (uVar5 != 0);
        *(undefined2 *)(puVar3 + 0x18) = 0xb003;
        *(undefined2 *)(puVar3 + 0x12) = 6;
        *puVar3 = 0;
        DAT_800ebb94[1] = 0x44;
        local_30 = (int)*(short *)(DAT_800ebb94 + 0x34);
        local_2c = (int)*(short *)(DAT_800ebb94 + 0x36);
        local_28 = (int)*(short *)(DAT_800ebb94 + 0x38);
        iVar6 = FUN_80074d64((int)*(short *)(DAT_800ebb94 + 0x34),
                             (int)*(short *)(DAT_800ebb94 + 0x38));
        iVar7 = FUN_80069f1c(&local_30,2,0x2000,1);
        if (iVar6 == 0) {
          bVar1 = iVar7 < *(short *)(DAT_800ebb94 + 0x36);
        }
        else {
          bVar1 = iVar6 < *(short *)(DAT_800ebb94 + 0x36);
        }
        if (bVar1) {
          DAT_800ebb94[0x21] = 10;
          puVar3 = DAT_800ebb94;
          DAT_800ebb94[1] = 0;
          *puVar3 = 0;
          puVar4 = DAT_800ebb94;
          uVar8 = 0;
          *(undefined2 *)(puVar3 + 6) = 0x1000;
          *(undefined2 *)(puVar4 + 0xe) = 0;
          puVar4[9] = 0;
        }
      }
      else {
        uVar8 = 0;
      }
    }
    bVar1 = uVar8 != 0;
    uVar8 = uVar8 + 1;
  } while (bVar1);
  DAT_800ebb94 = puVar2;
  *puVar2 = 0x55;
  puVar3 = DAT_800ebb94;
  *(undefined2 *)(puVar2 + 0x18) = 0x8000;
  puVar3[1] = 0;
  return;
}
