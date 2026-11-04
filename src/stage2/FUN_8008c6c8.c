/* FUN_8008c6c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c6c8  body 0x8008c6c8..0x8008c8a7  size 480 B
 * body sha256 b88ce4dbeed5a567d74368ab2f094ec92a2c55564e9ae74bec35966663650649
 * provider record sha256 d7d522c8555eef25433e35c56e57afdea9bd806e5237e8a35609726e691f7d58
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008c6c8(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  
  if (param_1 == 1) {
    uVar2 = DAT_800e8b38 - 2;
    puVar6 = &UNK_800c76ac + uVar2 * 4;
    iVar4 = uVar2 * 4 + 8;
    while( true ) {
      uVar2 = uVar2 - 1;
      (&DAT_800e8ec4)[iVar4] = puVar6[0x21818];
      iVar1 = (uVar2 >> 1) + uVar2;
      (&DAT_800e8ec5)[iVar4] = puVar6[0x21819];
      (&DAT_800e8ec6)[iVar4] = puVar6[0x2181a];
      FUN_8008cb48(iVar1,iVar1 + 3);
      if (uVar2 == 0) break;
      puVar6 = puVar6 + -4;
      iVar4 = iVar4 + -4;
    }
    if (((int)(uint)DAT_8012bfa0 < (int)(DAT_800e8b38 - 2)) && (DAT_8012bfa0 != 0x80)) {
      DAT_8012bfa0 = DAT_8012bfa0 + 2;
      return;
    }
  }
  else {
    uVar3 = 0;
    uVar2 = 0;
    puVar5 = &DAT_800c76b0;
    iVar4 = 8;
    do {
      *(undefined1 *)(puVar5 + 0x8606) = (&DAT_800e8ec8)[iVar4];
      *(undefined1 *)((int)puVar5 + 0x21819) = (&DAT_800e8ec9)[iVar4];
      *(undefined1 *)((int)puVar5 + 0x2181a) = (&DAT_800e8eca)[iVar4];
      FUN_8008cb48(uVar2 + uVar3 + 3);
      uVar3 = uVar3 + 1;
      uVar2 = uVar3 >> 1;
      puVar5 = puVar5 + 1;
      iVar4 = iVar4 + 4;
    } while (uVar3 < DAT_800e8b38 - 2);
    FUN_8008c314(DAT_800e8b38 - 1,0,0,0);
    FUN_8008cc1c(0xb);
    FUN_8008c314(DAT_800e8b38 - 2,0,0,0);
    FUN_8008cc1c(0xc);
    if ((1 < DAT_8012bfa0) && (DAT_8012bfa0 != 0x80)) {
      DAT_8012bfa0 = DAT_8012bfa0 - 2;
      return;
    }
  }
  DAT_8012bfa2 = 0;
  DAT_8012bfa0 = 0x80;
  return;
}
