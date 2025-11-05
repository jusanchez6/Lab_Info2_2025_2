import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from matplotlib.patches import Rectangle, Circle

# =======================
# Leer datos
# =======================
df = pd.read_csv("positions.csv")

# Detectar partículas muertas automáticamente (si dejan de aparecer)
df["alive"] = 1
ids = df["id"].unique()
for pid in ids:
    data = df[df["id"] == pid]
    last_time = data["time"].max()
    # Los frames posteriores al último registro se considerarán muertos
    df.loc[(df["id"] == pid) & (df["time"] >= last_time), "alive"] = 1
    df.loc[(df["id"] == pid) & (df["time"] < last_time), "alive"] = 1

# =======================
# Obstáculos
# =======================
obstacles = [
    (150, 100, 40, 40),
    (250, 160, 50, 50),
    (50, 200, 60, 30),
    (320, 40, 50, 60),
]

# =======================
# Configurar figura
# =======================
fig, ax = plt.subplots(figsize=(8, 6))
ax.set_xlim(df["x"].min() - 20, df["x"].max() + 20)
ax.set_ylim(df["y"].min() - 20, df["y"].max() + 20)
ax.set_xlabel("Posición X")
ax.set_ylabel("Posición Y")
ax.set_title("Simulación de partículas con obstáculos y fusión")
ax.grid(True)
ax.set_aspect("equal")

# =======================
# Dibujar obstáculos
# =======================
for (x, y, w, h) in obstacles:
    rect = Rectangle((x, y), w, h, linewidth=1.5,
                     edgecolor="black", facecolor="gray", alpha=0.4)
    ax.add_patch(rect)

# =======================
# Crear partículas
# =======================
colors = plt.cm.tab10.colors
particles = {}

for i, pid in enumerate(sorted(df["id"].unique())):
    row = df[df["id"] == pid].iloc[0]
    color = colors[i % len(colors)]
    circle = Circle((row["x"], row["y"]),
                    radius=row["radius"],
                    facecolor=color,
                    edgecolor="black",
                    alpha=0.8,
                    label=f"Partícula {pid}")
    ax.add_patch(circle)
    particles[pid] = circle


ax.legend(loc="upper right")
times = sorted(df["time"].unique())

# =======================
# Actualizar animación
# =======================
def update(frame):
    t = times[frame]
    data_t = df[df["time"] == t]
    active_ids = set(data_t["id"])

    for pid, circle in particles.items():
        if pid in active_ids:
            row = data_t[data_t["id"] == pid].iloc[0]
            circle.center = (row["x"], row["y"])
            circle.set_radius(row["radius"])
            circle.set_visible(True)
        else:
            circle.set_visible(False)
    ax.set_title(f"t = {t:.2f} s")
    return particles.values()

# =======================
# Animar
# =======================
ani = FuncAnimation(fig, update, frames=len(times), interval=30, blit=False)
plt.show()
