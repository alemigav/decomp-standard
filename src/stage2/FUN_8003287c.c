/* FUN_8003287c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003287c  body 0x8003287c..0x80032b07  size 652 B
 * body sha256 012978d37e4b868ddd376e52b6d4a1ea5593d62e242385ee12cfedbc138e3d6e
 * provider record sha256 5e59c933a43522cfa63532f86eee8e361e6ffbd637f9e2be64167cf5996de495
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003287c(uint param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined *puVar4;
  ushort *puVar5;
  int iVar6;
  uint uVar7;
  
  if (*(int *)(&DAT_800e15f0 + (param_1 - 0x10) * 4) != 0) {
    uVar7 = param_1;
    if (param_1 - 0x10 < 0x10) {
      uVar7 = 0x10;
    }
    iVar6 = 0;
    if (uVar7 == 0x10) {
      iVar6 = 1;
      puVar4 = &DAT_800c76b4;
      do {
        if (*(short *)(puVar4 + 0x1a240) == 0x10) {
          *(undefined2 *)(puVar4 + 0x1a242) = 1;
          iVar3 = (param_1 - 0x10) * 4;
          *(undefined4 *)(&DAT_800e1470 + iVar3) =
               *(undefined4 *)(&DAT_800e15f0 + iVar3 + iVar6 * 0x180);
          return;
        }
        iVar6 = iVar6 + -1;
        puVar4 = puVar4 + -4;
      } while (-1 < iVar6);
      if (DAT_800e18f6 == 0) {
        iVar6 = 1;
      }
      else if (DAT_800e18f2 == 0) {
        iVar6 = 0;
      }
    }
    else {
      puVar2 = &DAT_800c76b0;
      do {
        iVar6 = iVar6 + 1;
        if (*(ushort *)(puVar2 + 0x6890) == uVar7) {
          *(undefined2 *)((int)puVar2 + 0x1a242) = 1;
          return;
        }
        puVar2 = puVar2 + 1;
      } while (iVar6 < 2);
      if (DAT_800e18f2 == 0) {
        iVar6 = 0;
      }
      else if (DAT_800e18f6 == 0) {
        iVar6 = 1;
      }
    }
    (&DAT_800e18f2)[iVar6 * 2] = 1;
    iVar3 = (param_1 - 0x10) * 4;
    (&DAT_800e18f0)[iVar6 * 2] = (short)uVar7;
    *(undefined4 *)(&DAT_800e1470 + iVar3) = *(undefined4 *)(&DAT_800e15f0 + iVar3 + iVar6 * 0x180);
    if (uVar7 == 0x39) {
      uVar7 = 0x2e;
    }
    uVar1 = cart_record((&UNK_800eb1f4)[uVar7]);
    if (iVar6 == 0) {
      FUN_800327ec(uVar1,uVar1);
    }
    else {
      puVar2 = (undefined4 *)cart_record((&PTR_DAT_800eb264)[iVar6][uVar7 - 0x10]);
      if (puVar2[3] != puVar2[2]) {
        FUN_800327ec(uVar1,puVar2);
        FUN_800888ec(*puVar2,DAT_8010b6f8,puVar2[1]);
        iVar3 = 0;
        uVar7 = puVar2[1];
        iVar6 = 0;
        if (uVar7 >> 2 != 0) {
          puVar5 = DAT_8010b6f8;
          do {
            iVar6 = iVar6 + 1;
            iVar3 = iVar3 + (uint)*puVar5;
            *(undefined1 *)(puVar2[2] + iVar3) = *(undefined1 *)(puVar5 + 1);
            puVar5 = puVar5 + 2;
          } while (iVar6 < (int)(uVar7 >> 2));
        }
      }
    }
  }
  return;
}
