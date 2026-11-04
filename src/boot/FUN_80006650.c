/* FUN_80006650
 * image   boot (boot), base 0x80000480
 * address 0x80006650  body 0x80006650..0x800066ef  size 160 B
 * body sha256 3d753cee9b894ddacd67475ab52da44a247fcbc446d154f36fd2ae04b463d690
 * provider record sha256 42c91d55bfb3a9abe557d340dbab8241af3f3be13f65399f8e64e8da4e06ab5e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80006650(undefined4 *param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  if (0xb < param_2) {
    uVar1 = -(int)param_1 & 3;
    if (uVar1 != 0) {
      uVar3 = (uint)param_1 & 3;
      *(uint *)((int)param_1 - uVar3) =
           *(uint *)((int)param_1 - uVar3) & -1 << (4 - uVar3) * 8 | 0U >> uVar3 * 8;
      param_1 = (undefined4 *)((int)param_1 + uVar1);
    }
    uVar3 = param_2 - uVar1 & 0xffffffe0;
    uVar1 = (param_2 - uVar1) - uVar3;
    if (uVar3 != 0) {
      puVar4 = (undefined4 *)(uVar3 + (int)param_1);
      puVar2 = param_1;
      do {
        *puVar2 = 0;
        puVar2[1] = 0;
        puVar2[2] = 0;
        puVar2[3] = 0;
        param_1 = puVar2 + 8;
        puVar2[4] = 0;
        puVar2[5] = 0;
        puVar2[6] = 0;
        puVar2[7] = 0;
        puVar2 = param_1;
      } while (param_1 != puVar4);
    }
    uVar3 = uVar1 & 0xfffffffc;
    param_2 = uVar1 - uVar3;
    if (uVar3 != 0) {
      puVar4 = (undefined4 *)(uVar3 + (int)param_1);
      puVar2 = param_1;
      do {
        param_1 = puVar2 + 1;
        *puVar2 = 0;
        puVar2 = param_1;
      } while (param_1 != puVar4);
    }
  }
  if (0 < param_2) {
    puVar2 = param_1;
    do {
      puVar4 = (undefined4 *)((int)puVar2 + 1);
      *(undefined1 *)puVar2 = 0;
      puVar2 = puVar4;
    } while (puVar4 != (undefined4 *)(param_2 + (int)param_1));
  }
  return;
}
