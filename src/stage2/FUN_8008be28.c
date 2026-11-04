/* FUN_8008be28
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008be28  body 0x8008be28..0x8008c053  size 556 B
 * body sha256 c5911c10c60a243972bdfd23e748f9b4f809578f4dc150312ab7753f5c8b969d
 * provider record sha256 43f9fb08f45460cbf97004097bb9fcb5c855aaa0b43dafc4f99fdb158e576452
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008be28(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (param_1 - 0xe < 2) {
    DAT_800dfbea = DAT_8012bfa0;
    DAT_800dfbeb = DAT_800e8b38;
    FUN_80083758(&DAT_800e8ce0,0x7f);
    iVar3 = 0xb;
    if (param_1 == 0xe) {
      iVar3 = 0;
      DAT_8012bfa2 = 3;
      DAT_8012bfa0 = 0;
    }
    else {
      DAT_8012bfa2 = 0;
      DAT_8012bfa0 = 0x80;
    }
    DAT_800e8b38 = 8;
    puVar2 = &DAT_800c76b0;
    do {
      *(undefined1 *)(puVar2 + 0x614f) = *(undefined1 *)(puVar2 + 0x8606);
      *(undefined1 *)((int)puVar2 + 0x1853d) = *(undefined1 *)((int)puVar2 + 0x21819);
      *(undefined1 *)((int)puVar2 + 0x1853e) = *(undefined1 *)((int)puVar2 + 0x2181a);
      iVar1 = (iVar3 + uVar4) * 3;
      *(undefined1 *)(puVar2 + 0x8606) = (&DAT_8012be78)[iVar1];
      *(undefined1 *)((int)puVar2 + 0x21819) = (&DAT_8012be79)[iVar1];
      uVar4 = uVar4 + 1;
      *(undefined1 *)((int)puVar2 + 0x2181a) = (&DAT_8012be7a)[iVar1];
      puVar2 = puVar2 + 1;
    } while (uVar4 < 0xb);
  }
  else {
    iVar3 = FUN_800837ac(&DAT_800e8ce0,0x7f);
    if (iVar3 != 0) {
      puVar2 = &DAT_800c76b0;
      do {
        *(undefined1 *)(puVar2 + 0x8606) = *(undefined1 *)(puVar2 + 0x614f);
        *(undefined1 *)((int)puVar2 + 0x21819) = *(undefined1 *)((int)puVar2 + 0x1853d);
        uVar4 = uVar4 + 1;
        *(undefined1 *)((int)puVar2 + 0x2181a) = *(undefined1 *)((int)puVar2 + 0x1853e);
        puVar2 = puVar2 + 1;
      } while (uVar4 < 10);
      DAT_800e8b38 = DAT_800dfbeb;
      DAT_8012bfa0 = DAT_800dfbea;
      if (DAT_800dfbea == 0x80) {
        DAT_8012bfa2 = 0;
      }
      else {
        DAT_8012bfa2 = (&DAT_800e8ec8)[(uint)DAT_800dfbea * 4];
      }
      if ((param_1 & 1) == 0) {
        DAT_800e8ef0 = 0x2f;
      }
      else {
        DAT_800e8ef0 = 0x30;
      }
      DAT_800e8ef1 = 1;
      DAT_800e8ef2 = 0;
    }
    FUN_80083780(&DAT_800e8ce0,0x7f);
  }
  return;
}
