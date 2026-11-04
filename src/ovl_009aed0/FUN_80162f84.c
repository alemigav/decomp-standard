/* FUN_80162f84
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80162f84  body 0x80162f84..0x80162fe3  size 96 B
 * body sha256 f00b18d2d08b018e73d57cb8ab8355c47e0f8d971f47ce289ed3b7405c757b87
 * provider record sha256 21a8479b56542592215c4c398e544ee3b6a01c5d097f648ab1fde3f180c012eb
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162f84(int param_1,int param_2)

{
  short sVar1;
  uint *puVar2;
  
  puVar2 = (uint *)(*(int *)(param_1 + 0x234) + param_2 * 0x178);
  *puVar2 = *puVar2 | 0x4a;
  sVar1 = *(short *)(param_1 + 0x66);
  *(undefined2 *)(puVar2 + 0x4e) = 0x8000;
  *(undefined2 *)(puVar2 + 0x4d) = 0;
  *(undefined2 *)((int)puVar2 + 0x132) = 0xfff6;
  *(undefined2 *)((int)puVar2 + 0x136) = 0;
  *(undefined2 *)(puVar2 + 0x4f) = 0;
  puVar2[0x18] = 0x202038;
  *(short *)(puVar2 + 0x4c) = sVar1 + 0x800;
  return;
}
