/* FUN_80165a5c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165a5c  body 0x80165a5c..0x80165aaf  size 84 B
 * body sha256 d3e749cd08c0180a6c38f38502f20964427d16c141c7b1f4812fd2deab1fe32c
 * provider record sha256 e793d3b64427d3c5f4326005c87d351ff1472b3bd4215a3e2925c2f3d9c02f3f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165a5c(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    *(undefined2 *)(param_1 + 0x4d) = 0xfe0c;
    *(undefined2 *)((int)param_1 + 0x13a) = 500;
    uVar2 = 0x4000000;
    uVar1 = *param_1 & 0xe7ffffff;
  }
  else {
    *(undefined2 *)(param_1 + 0x4d) = 0xfc18;
    *(undefined2 *)((int)param_1 + 0x13a) = 1000;
    uVar1 = *param_1;
    uVar2 = 0xc000000;
  }
  *param_1 = uVar1 | uVar2;
  return;
}
