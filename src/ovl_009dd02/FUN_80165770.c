/* FUN_80165770
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80165770  body 0x80165770..0x8016580f  size 160 B
 * body sha256 d6239a3a756719c624b7006a08950725c56ba2e7ecb67faecd870c9eed3d9da7
 * provider record sha256 e33156869e0bc046032d24145730f04f88c578e7ae378e6b05ad1bb1969c73d2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165770(int param_1,uint param_2,uint param_3)

{
  undefined2 uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  
  if (param_2 < param_3) {
    iVar4 = param_2 * 0x178;
    do {
      puVar2 = (uint *)(*(int *)(param_1 + 0x234) + iVar4);
      uVar3 = *puVar2;
      if ((DAT_800e9012 & 8) != 0) {
        uVar3 = uVar3 | 0x4a;
      }
      *puVar2 = uVar3 & 0xffff7fff;
      uVar1 = *(undefined2 *)(param_1 + 0x66);
      param_2 = param_2 + 1;
      *(undefined2 *)(puVar2 + 0x4e) = 0;
      *(undefined2 *)(puVar2 + 0x4d) = 300;
      *(undefined2 *)((int)puVar2 + 0x132) = 0xff6a;
      *(undefined2 *)((int)puVar2 + 0x136) = 10;
      *(undefined2 *)(puVar2 + 0x4f) = 0xff9c;
      puVar2[0x18] = 0x104010;
      *(undefined2 *)(puVar2 + 0x4c) = uVar1;
      iVar4 = iVar4 + 0x178;
    } while (param_2 < param_3);
  }
  return;
}
