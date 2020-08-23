#!/usr/bin/env python3
import click
import os
from time import sleep


@click.command(
    "signal_barrage",
    help="Given a PID, sends a barrage of SIGUSR1 signals at said process.",
)
@click.argument("pid")
@click.option(
    "--count", default=1_000, help="The number of signals to send. Defauls to 1,000"
)
@click.option(
    "--signum",
    default=10,
    type=int,
    help="The signal to send. Defaults to SIGUSR1 (10 on this container)",
)
@click.option(
    "--sleep-time",
    default=1,
    type=int,
    help="How much time, in milliseconds to wait between each signal that gets sent",
)
def main(pid, count, signum, sleep_time):
    for i in range(count):
        os.kill(pid, signum)
        if sleep_time > 0:
            sleep(sleep_time / 1000.0)


if __name__ == "__main__":
    main()
