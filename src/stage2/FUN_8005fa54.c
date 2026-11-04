/* FUN_8005fa54
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005fa54  body 0x8005fa54..0x8005fb53  size 256 B
 * body sha256 73f2ec582350661f1d1673dc03374df08eccd3de83f191c4a7481c45a26c70e2
 * provider record sha256 b55b097cbe4a78b7ebc7c9cf58dff2612887aa3f8aac467dec1f64afbea18514
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8005fa54(int param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined2 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  int iVar10;
  
  iVar10 = 6;
  puVar9 = (undefined4 *)(*(int *)(param_1 + 0x234) + 0x1d60);
  piVar8 = (int *)(*(int *)(param_1 + 0x234) + 0x1e8c);
  do {
    puVar7 = puVar9 + 2;
    iVar6 = 2;
    puVar5 = &DAT_800e9048;
    *(undefined1 *)(piVar8 + 1) = 0xff;
    *puVar9 = 0;
    piVar8[0x13] = 0;
    do {
      iVar3 = 2;
      puVar2 = puVar5;
      puVar4 = puVar7;
      do {
        uVar1 = *puVar2;
        puVar2 = puVar2 + 1;
        iVar3 = iVar3 + -1;
        *(undefined2 *)puVar4 = uVar1;
        puVar4 = (undefined4 *)((int)puVar4 + 2);
      } while (iVar3 != -1);
      puVar7 = (undefined4 *)((int)puVar7 + 6);
      iVar6 = iVar6 + -1;
      puVar5 = puVar5 + 3;
    } while (iVar6 != -1);
    FUN_800424ec(piVar8[-0x32],puVar9 + 2,puVar9 + 0xe);
    puVar9 = puVar9 + 0xbc;
    *(undefined2 *)((int)piVar8 + -0x16) = *(undefined2 *)(param_1 + 0x66);
    iVar6 = *(int *)(param_1 + 0x234);
    iVar10 = iVar10 + -1;
    piVar8[-0x32] = iVar6 + 0x1060;
    *piVar8 = iVar6 + 0x1028;
    piVar8 = piVar8 + 0xbc;
  } while (iVar10 != 0);
  *(undefined2 *)(*(int *)(param_1 + 0x234) + 0x1144) = 0;
  return 0;
}
