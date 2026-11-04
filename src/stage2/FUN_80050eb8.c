/* FUN_80050eb8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80050eb8  body 0x80050eb8..0x80050f37  size 128 B
 * body sha256 fd7de973ed822fa53d582fdcba1581b0fa8e6ef8055ca573bd022ab5b1e566cd
 * provider record sha256 b6db5ef102f32ee6947fbff1aad61189ec2a1cee85844b739ca5ecd0111d79ba
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80050eb8(int param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  if ((*(ushort *)(param_1 + 0x66) & 0x400) == 0) {
    uVar1 = *(undefined2 *)(param_1 + 0x132);
    uVar2 = *(undefined2 *)(param_1 + 0x136);
    uVar3 = *(undefined2 *)(param_1 + 0x138);
    *(undefined2 *)(param_1 + 0x13c) = *(undefined2 *)(param_1 + 0x130);
  }
  else {
    uVar1 = *(undefined2 *)(param_1 + 0x130);
    uVar2 = *(undefined2 *)(param_1 + 0x138);
    uVar3 = *(undefined2 *)(param_1 + 0x136);
    *(undefined2 *)(param_1 + 0x13c) = *(undefined2 *)(param_1 + 0x132);
  }
  *(undefined2 *)(param_1 + 0x13e) = uVar1;
  *(undefined2 *)(param_1 + 300) = uVar2;
  *(undefined2 *)(param_1 + 0x12e) = uVar3;
  *(int *)(param_1 + 0x120) = *(int *)(param_1 + 0x28) + (int)*(short *)(param_1 + 0x13c);
  *(int *)(param_1 + 0x124) = *(int *)(param_1 + 0x2c) + (int)*(short *)(param_1 + 0x134);
  *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x30) + (int)*(short *)(param_1 + 0x13e);
  return;
}
