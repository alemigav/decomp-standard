/* FUN_8004a0a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004a0a8  body 0x8004a0a8..0x8004a23b  size 404 B
 * body sha256 695f2ef83d019d1ad2afee18f9830ab11c38916ad16817071bc1b24370d5ee4d
 * provider record sha256 ece8813e65b7d6efa84b3efef015f88e51777e45ee263a00858ed6f01f3036d7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004a0a8(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  puVar4 = *(undefined4 **)(param_1 + 0x234);
  puVar3 = *(undefined4 **)(param_1 + 0x240);
  uVar5 = (uint)*(byte *)(param_1 + 0x1a3);
  puVar2 = puVar3 + 0x50;
  puVar1 = puVar4 + 0x50;
  do {
    *puVar3 = *puVar4;
    uVar6 = puVar1[-0x4d];
    uVar7 = puVar1[-0x4c];
    uVar8 = puVar1[-0x4b];
    puVar2[-0x4e] = puVar1[-0x4e];
    puVar2[-0x4d] = uVar6;
    puVar2[-0x4c] = uVar7;
    puVar2[-0x4b] = uVar8;
    uVar6 = puVar1[-0x49];
    uVar7 = puVar1[-0x48];
    uVar8 = puVar1[-0x47];
    puVar2[-0x4a] = puVar1[-0x4a];
    puVar2[-0x49] = uVar6;
    puVar2[-0x48] = uVar7;
    puVar2[-0x47] = uVar8;
    uVar6 = puVar1[-0x41];
    uVar7 = puVar1[-0x40];
    uVar8 = puVar1[-0x3f];
    puVar2[-0x42] = puVar1[-0x42];
    puVar2[-0x41] = uVar6;
    puVar2[-0x40] = uVar7;
    puVar2[-0x3f] = uVar8;
    uVar6 = puVar1[-0x3d];
    uVar7 = puVar1[-0x3c];
    uVar8 = puVar1[-0x3b];
    puVar2[-0x3e] = puVar1[-0x3e];
    puVar2[-0x3d] = uVar6;
    puVar2[-0x3c] = uVar7;
    puVar2[-0x3b] = uVar8;
    puVar2[-0x37] = puVar1[-0x37];
    puVar2[-5] = puVar1[-5];
    *(undefined2 *)(puVar2 + -9) = *(undefined2 *)(puVar1 + -9);
    *(undefined1 *)((int)puVar2 + -0x2f) = *(undefined1 *)((int)puVar1 + -0x2f);
    *(undefined1 *)((int)puVar2 + -0x2e) = *(undefined1 *)((int)puVar1 + -0x2e);
    *(undefined2 *)((int)puVar2 + -0x22) = *(undefined2 *)((int)puVar1 + -0x22);
    uVar6 = puVar1[-6];
    puVar2[-7] = puVar1[-7];
    puVar2[-6] = uVar6;
    uVar6 = puVar1[-10];
    puVar2[-0xb] = puVar1[-0xb];
    puVar2[-10] = uVar6;
    uVar6 = puVar1[-0x39];
    puVar2[-0x3a] = puVar1[-0x3a];
    puVar2[-0x39] = uVar6;
    uVar6 = puVar1[-0x45];
    puVar2[-0x46] = puVar1[-0x46];
    puVar2[-0x45] = uVar6;
    puVar2[-4] = puVar1[-4];
    puVar4 = puVar4 + 0x5e;
    puVar2[-3] = puVar1[-3];
    uVar5 = uVar5 - 1;
    puVar2[-2] = puVar1[-2];
    puVar3 = puVar3 + 0x5e;
    puVar2[-1] = puVar1[-1];
    uVar6 = *puVar1;
    puVar1 = puVar1 + 0x5e;
    *puVar2 = uVar6;
    puVar2 = puVar2 + 0x5e;
  } while (uVar5 != 0);
  return;
}
